#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph{
    
  public:
  unordered_map<T, list<pair<T,T>>> adjList;
  
  void addEdge(T u, T v,T wt,  T dir){
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
          for(pair<T,T> p : i.second){
              cout<<" { "<< p.first<<" ,  " << p.second<<" }  ";
              // 1 : {  {2 ,5} , {}, };
          }
          cout<<" } "<<endl;
      }
  }
};
int main(){
    Graph<int> g;
    g.addEdge(1,3,30, 0);
    g.addEdge(3,2,40,0);
    g.addEdge(2,5,60,0);
    g.printAdjList();
}
