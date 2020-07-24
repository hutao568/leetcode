//
// Created by tao hu on 2020/7/7.
//
#include "vector"
#include "iostream"
using namespace std;

class Solution {
 public:
  class DSU{
   public:
    vector<int> arr1;
    DSU(int size){
      arr1.push_back(0);
      for(int i=1;i<size;i++){
        arr1.push_back(i);
      }
    }
    int find(int index){
      int root=arr1[index];
      while(root!=arr1[root]){
        root=arr1[root];
      }
      return root;
    }
    void Union(int index1,int index2){
      int r1=find(index1);
      int r2=find(index2);
      if(r1==r2)
        return ;
      arr1[index2]=r1;
      return ;
    }
  };
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n=edges.size();
    DSU dsu(n);
    for(auto edge:edges){
      if(dsu.find(edge[0])==dsu.find(edge[1]))
        return {edge[0],edge[1]};
      dsu.Union(edge[0],edge[1]);
    }
    return {-1,-1};
  }
};

int main(){
  Solution obj;
  vector<vector<int>> arr={{1,2},{1,3},{2,3}};
  vector<int> ans=obj.findRedundantConnection(arr);
  return 0;
}