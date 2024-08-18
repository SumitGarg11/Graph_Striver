#include <bits/stdc++.h>
using namespace std;
class Graph{
    public:
   // adjList
   unordered_map<int, list<pair<int,int>>> adjList;
   void addEdge(int u, int v, int wt, bool dir){
       if(dir == 0){
           // undirected graph
           adjList[u].push_back({v,wt});
           adjList[v].push_back({u,wt});
       }
       else{
           adjList[u].push_back({v,wt});
       }
   }
   void print(){
       for(auto i : adjList){
           cout<<i.first <<" : { ";
           for(auto nbr : i.second){
               cout<<" { "<<nbr.first<<" , "<< nbr.second<<" } , ";
           }
           cout<<"  } "<< endl;
       }
   }
   bool isCycleUndirected(int root, unordered_map<int,bool> &vis){
       queue<int> q;
      
       unordered_map<int,int> parent;
       q.push(root);
       vis[root] = true;
       parent[root] = -1;
       while(!q.empty()){
           int frontNode = q.front();
           q.pop();
           for(auto nbr : adjList[frontNode]){
               int nbrData = nbr.first;
               if(!vis[nbrData]){
                   vis[nbrData] = true;
                   q.push(nbrData);
                   parent[nbrData] = frontNode;
               }
               else if(vis[nbrData] == true && nbrData  != parent[frontNode]){
                   return true;
               }
           }
       }
       return false;
   }
   
};
int main(){
    Graph g;
    g.addEdge(0,1,10,1);
    g.addEdge(1,2,100,1);
    g.addEdge(2,4,100,1);
    g.addEdge(2,5,1100,1);
    g.addEdge(1,3,200, 1);
     g.addEdge(3,4,333,1);
    
    g.print();
    cout<<endl;
    // bool IsCycle = g.isCycleUndirected(1);
    // if(IsCycle){
    //     cout<<"Yes Cycle Present";
    // }
    // else cout<<"Not present";
     unordered_map<int, bool> vis;
     for(int i = 0; i<= 5; i++){
         if(!vis[i]){
             bool ans = g.isCycleUndirected(i,vis);
             if(ans == true){
                 cout<<"Cycle";
             }
             else cout<<"Not Cycle";
         }
     }
    
    
}
