//
// Created by tao hu on 2020/7/13.
//
#include "vector"
#include "unordered_map"
#include "iostream"
#include "queue"
using namespace  std;

class Solution {

 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<vector<int>> G(n);
    vector<int> indegree(n);
    for(auto edge:edges){
      G[edge[0]].push_back(edge[1]);
      G[edge[1]].push_back(edge[0]);
      indegree[edge[0]]++;
      indegree[edge[1]]++;
    }
    vector<int> Q;
    for(int i=0;i<indegree.size();i++){
      if(indegree[i]==1){
        Q.push_back(i);
      }
    }
    vector<int> Q_;
    while(n>2){
      n-=Q.size();
      for(int i=0;i<Q.size();i++){
        auto cur=Q[i];
        for(auto next:G[cur]){
          if(indegree[next]>0){
            indegree[next]--;
            if(indegree[next]==1){
              Q_.push_back(next);
            }

          }
        }
      }
      Q=Q_;
      Q_.clear();
    }
    return Q;
  }

};

int main(){

  Solution obj;
  vector<vector<int>> edges={{3,0},{3,1},{3,2},{3,4},{5,4}};
  auto res=obj.findMinHeightTrees(6,edges);
  return 0;
}

//6
//[[3,0],[3,1],[3,2],[3,4],[5,4]]