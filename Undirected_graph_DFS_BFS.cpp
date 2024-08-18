// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>> adjList;
    void addEdge(int u, int v, bool dir){
        adjList[u].push_back(v);
        if(!dir){
            adjList[v].push_back(u);
        }
    }
    void print(){
        for(auto i : adjList){
            cout<<i.first<<" : { ";
            for(auto nbr : i.second){
                cout<<nbr<<" , ";
            }
            cout<<" } "<<endl;
        }
    }
    void bfs(int root,unordered_map<int,bool> &vis){
        
        queue<int> q;
        q.push(root);
        vis[root] = true;
        while(!q.empty()){
            int frontNode = q.front();
            cout<<frontNode<<" ";
            q.pop();
            for(auto nbr : adjList[frontNode]){
                if(!vis[nbr]){
                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }
    void dfs(int root, unordered_map<int,bool> &vis){
        vis[root] = true;
        cout<<root<<" ";
        for(auto nbr : adjList[root]){
        
            if(!vis[nbr]){
                vis[nbr] = true;
                dfs(nbr, vis);
            }
        }
    }
};
int main() {
    Graph g;
    
   int V,E;
   cout<<"Vertex: ";
   cin>>V;
   cout<<"Edges: ";
   cin>>E;
   bool dir;
   cout<<"dir : ";
   cin>>dir;
   for(int i =0; i<E; i++)
{       int u,v;
       cin>>u>>v;
       g.addEdge(u,v,dir);
   }
   g.print();
   
   unordered_map<int,bool> vis;
   for(int i =0; i<V; i++){
       if(!vis[i]){
           g.dfs(i,vis);
       }
   }
   cout<<endl;
   
    return 0;
}
