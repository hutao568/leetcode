//
// Created by tao hu on 2020/7/24.
//

class Solution {
 public:
  int helper(int numBottles, int numExchange,int resBottles){
    if((numBottles+resBottles)<numExchange)
      return numBottles;
    return numBottles+helper((numBottles+resBottles)/numExchange,numExchange,(numBottles+resBottles)%numExchange);
  }
  int numWaterBottles(int numBottles, int numExchange) {
    return helper(numBottles,numExchange,0);
  }
};