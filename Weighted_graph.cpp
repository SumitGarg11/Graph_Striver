#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, bool dir) {
        // Add edge from u to v with weight wt
        adjList[u].push_back({v, wt});
        if (!dir) {
            // Add edge from v to u with weight wt (if undirected)
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList() {
        for (const auto& i : adjList) {
            cout << i.first << " : { "; // Source Node
            for (const auto &p : i.second) {
                cout << " { " << p.first << " , " << p.second << " } ";
            }
            cout << " }" << endl;
        }
    }
};

int main() {
    Graph g;
    
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    
    cout << "Enter the number of edges: ";
    cin >> E;
    
    bool dir;
    cout << "Enter 1 for directed or 0 for undirected: ";
    cin >> dir;
    
    cout << "Enter the edges (u v wt):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        g.addEdge(u, v, wt, dir);
    }
    
    cout << "Adjacency List:" << endl;
    g.printAdjList();
    
    return 0;
}
