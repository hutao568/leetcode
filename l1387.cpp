//
// Created by tao hu on 2020/7/9.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
 public:
  int getW(int num,vector<int> &memory){
    if(memory[num]!=0)
      return memory[num];
    if(num==1)
      return 0;
    else{
      if(num%2==0){
        return getW(num/2,memory)+1;
      }
      else{
        return getW(3*num+1,memory)+1;
      }
    }
  }
  int getKth(int lo, int hi, int k) {
    vector<int> memory(3*hi+1,0);
    vector<pair<int,int>> weight;
    for(int i=lo;i<=hi;i++){
      weight.push_back({memory[i],i});
    }
    sort(weight.begin()+lo,weight.end(),[&](pair<int,int> num1,pair<int,int> num2){
           if(num1.first==num2.first)  return num1.second<num2.second;
           else    return num1.first<num2.first;
         }
    );
    return weight[k-1].second;
  }
};

int main()
{
  Solution obj;
  cout<<obj.getKth(10,20,5);
}