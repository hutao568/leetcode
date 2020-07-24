//
// Created by tao hu on 2020/6/26.
//
#include "vector"
#include "set"
#include "string"
using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    set<string> wordSet;
    for(auto &word:wordDict){
      wordSet.insert(word);
    }

    int n=s.length();
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
      for(int j=i-1;j>=0;j--){
        if(dp[j]==1&&wordSet.find(s.substr(j,i))!=wordSet.end())
        {
          dp[i]=1;
          break;
        }
      }
    }
    return dp[n];
  }
};

int main(){
  Solution solution;
  string s="applepenapple";
  vector<string> wordDict={"apple", "pen"};
  solution.wordBreak(s,wordDict);
}