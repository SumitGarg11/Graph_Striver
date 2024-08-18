#include <bits/stdc++.h>
using namespace std;
class Graph{
    public :
    unordered_map<int,list<int>> adjList;
    void addEdge(int u, int v, bool dir){
    if(dir == 1){
        adjList[u].push_back(v);
    }
    else{
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
void print(){
    for(auto it : adjList){
        cout<<it.first<<" : { ";
        for(auto nbr : it.second){
            cout<<nbr<<" , ";
        }
        cout<<" } "<<endl;
    }
}
};
int main(){
    Graph g;
    int V,E;
    cout<<"Vertices: ";
    cin>>V;
    cout<<"Edge: ";
    cin>>E;
    // 
    bool dir;
    cout<<"dir:";
    cin>>dir;
    for(int i =0; i<E; i++){
        int u,v;
       cin>>u>>v;
        
        g.addEdge(u,v,dir);
    }
    g.print();
    
}
