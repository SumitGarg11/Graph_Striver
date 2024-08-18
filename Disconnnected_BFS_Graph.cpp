#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph{
    
  public:
  unordered_map<T, list<pair<T,int>>> adjList;
  
  void addEdge(T u, T v,int wt,  int dir){
      if(dir == 1){
         adjList[u].push_back({v, wt});
      }
      else{
          adjList[u].push_back({v,wt});
          adjList[v].push_back({u,wt});
      }
  }
  void printAdjList(){
      for(auto i : adjList){
          cout<<i.first<<" : { "; // source Node;
          for(pair<T,int> p : i.second){
              cout<<" { "<< p.first<<" ,  " << p.second<<" }  ";
              // 1 : {  {2 ,5} , {}, };
          }
          cout<<" } "<<endl;
      }
  }
  void bfs(T root, unordered_map<T,bool> &vis){
      // visted container 
      
      queue<T> q;
      // initial 
      q.push(root);
      vis[root] = true;
      while(!q.empty()){
          T frontNode  = q.front();
          cout<<frontNode<<" ";
          q.pop();
          for(auto nbr : adjList[frontNode]){
              T nbrdata = nbr.first;
              
              if(!vis[nbrdata]){
                  q.push(nbrdata);
                  vis[nbrdata] = true; 
              }
          }
      }
  }
};
int main(){
    Graph<char> g;
    g.addEdge('a','b',30, 0);
    g.addEdge('a','c',40,0);
    g.addEdge('b','d',60,0);
    g.addEdge('c','e',90, 0);
    g.addEdge('e','f',40,0);
    g.addEdge('c','f',60,0);
    g.printAdjList();
    cout<<endl;
     unordered_map<char,bool> vis;
    for(char node = 'a'; node <= 'f'; node++){
        if(!vis[node]){
            g.bfs(node,vis);
        }
    }
}
