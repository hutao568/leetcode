//
// Created by tao hu on 2020/7/24.
//

class Solution {
 public:
  int balancedStringSplit(string s) {
    int L=0,R=0;
    int ans=0;
    for(auto ch:s){
      if(ch=='R')
        R++;
      else
        L++;
      if(L==R){
        L=0;
        R=0;
        ans+=1;
      }
    }
    return ans;
  }
};