//
// Created by tao hu on 2020/7/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool dfs(vector<vector<int>> &graph,vector<int> &color,int cur){
    for(int i=0;i<graph[cur].size();i++){
      if(color[graph[cur][i]]<0){
        if(color[cur]==0)
          color[graph[cur][i]]=1;
        else
          color[graph[cur][i]]=0;
        dfs(graph,color,graph[cur][i]);
      }
      else{
        if(color[graph[cur][i]]==color[cur]){
          return false;
        }
        else
          continue;
      }
    }
    return true;
  }
  bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> color(n,-1);
    for(int i=0;i<n;i++){
      if(color[i]<0){
        color[i]=0;
        if(!dfs(graph,color,i))
          return false;
      }
    }
    return true;
  }
};

int main(){
  Solution obj;
  vector<vector<int>> graph={{1,3},{0,2},{1,3},{0,2}};
  obj.isBipartite(graph);
}