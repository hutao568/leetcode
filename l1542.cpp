#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestAwesome(string s) {
    int state=0;
    int ans=0;
    vector<int> index(1024,INT_MAX);
    index[0]=-1;
    for(int i=0;i<s.length();i++){
      state^=1<<(s[i]-'0');
      ans=max(ans,i-index[state]);
      for(int j=0;j<10;j++){
        int temp=state^(1<<j);
        ans=max(ans,i-index[temp]);
      }
      index[state]=min(index[state],i);
    }
    return ans;
  }
};


int main(){
  Solution solution;
  solution.longestAwesome("213123");
}