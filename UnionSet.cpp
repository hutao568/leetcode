//
// Created by tao hu on 2020/7/6.
//
#include <vector>
using namespace std;

class UnionSet(){
  vector<int> root;
  UnionSet(int n){
    root=vector<int>(n);
    for(int i=0;i<n;i++)
      root[i]=i;
  }

  int find(int index){
    // 路径压缩
    return root[index]==index?index:root[index]=find(root[index]);
  }

  void Union(int x,int y){
    int rx=find(x);
    int ry=find(y);
    if(rx!=ry){
      root[rx]=ry;
    }
  }
}