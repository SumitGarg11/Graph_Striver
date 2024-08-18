#include <bits/stdc++.h>
using namespace std;
class Graph{
  public:
  unordered_map<int, list<pair<int,int>>> adjList;
  
  void addEdge(int u, int v,int wt,  bool dir){
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
          for(pair<int,int> p : i.second){
              cout<<" { "<< p.first<<" ,  " << p.second<<" }  ";
              // 1 : {  {2 ,5} , {}, };
          }
          cout<<" } "<<endl;
      }
  }
};
int main(){
    Graph g;
    g.addEdge(1,3,30, 0);
    g.addEdge(3,2,40,0);
    g.addEdge(2,5,60,0);
    g.printAdjList();
}
