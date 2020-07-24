//
// Created by tao hu on 2020/7/10.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
 public:
  int maxSumAfterPartitioning(vector<int>& A, int K) {
    int n=A.size();
    vector<int> dp(n+1,0);

    for(int i=1;i<=n;i++){
      for(int j=1;j<=K&&(i-j)>=0;j++){
        dp[i]=max(dp[i],dp[i-j]+j*(*max_element(A.begin()+i-j,A.begin()+i)));
      }
    }
    return dp[n];
  }
};

int main(){

  Solution obj;
  vector<int> arr={1,15,7,9,2,5,10};
  cout<<obj.maxSumAfterPartitioning(arr,3);

}