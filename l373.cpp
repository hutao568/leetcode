//
// Created by tao hu on 2020/7/7.
//
#include "queue"
using namespace std;

class Solution {
 public:
  struct node{
    int x1,x2;
    node(int y1,int y2):x1(y1),x2(y2){}
    bool operator<(node x) const{
      return (this->x1+this->x2)<(x.x1+x.x2);
    }
  };

  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<node> queue;
    for(int i=0;i<nums1.size();i++){
      for(int j=0;j<nums2.size();j++){
        if(queue.size()<k){
          queue.push(node(nums1[i],nums2[j]));
        }
        else{
          if((queue.top().x1+queue.top().x2)>(nums1[i]+nums2[j])){
            queue.pop();
            queue.push(node(nums1[i],nums2[j]));
          }
        }
      }
    }
    vector<vector<int>> ans;
    while(!queue.empty()){
      ans.push_back({queue.top().x1,queue.top().x2});
    }
    return ans;
  }
};

int main(){
  Solution s;
  vector<int> a1={1,7,11};
  vector<int> a2={2,4,6};
  s.kSmallestPairs(a1,a2,3);
}