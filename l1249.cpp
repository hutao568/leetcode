//
// Created by tao hu on 2020/7/20.
//
#include <string>
using namespace  std;
#include <vector>
#include <iostream>
class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    int n=s.size();
    vector<bool> flag(n,true);
    vector<int> pos;
    for(int i=0;i<s.size();i++){
      if(s[i]=='('){
        pos.push_back(i);
        flag[i]= true;
      }
      else if(s[i]==')'){
        if(pos.size()){
          pos.pop_back();

        }
        else{
          flag[i]=false;
        }
      }
      else{
        flag[i]=true;
      }
    }
    while(pos.size()){
      flag[pos.back()]=false;
      pos.pop_back();
    }
    string ans;
    for(int i=0;i<n;i++){
      if(flag[i])
        ans.push_back(s[i]);
    }
    return ans;
  }
};

int main(){
  Solution obj;
  cout<<obj.minRemoveToMakeValid("lee(t(c)o)de)");
}