
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool dir){
        // dir -> 1 = directed graph
        // dir -> 0 = undirected graph 
        if(dir == 1){
            // graph is directed 
            // u -> v;
            adjList[u].push_back(v);
        }
        else {
            // graph is undirected graph
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        // cout<<"Print the AdjList : ";
        // printAdjList();
        // cout<<endl;
    }
    void printAdjList(){
        for(auto i : adjList){
            cout<<i.first<<"-> { " ;
            for(auto neighbour: i.second){
                cout<<neighbour<<" , ";
            }
            cout<<" } ";
        }
        
    }
};

int main() {
  Graph g;
  g.addEdge(1,3,0);
  g.addEdge(1, 2,0);
  g.addEdge(2,4,0);
  g.addEdge(3,4,0);
  g.addEdge(3,5,0);
  g.addEdge(4,5,0);
  cout<<endl;
  g.printAdjList();

    return 0;
}
