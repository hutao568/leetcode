#include "vector"
#include "unordered_map"
#include "iostream"

class Solution {
 public:
  bool lemonadeChange(std::vector<int>& bills) {
    std::unordered_map<int,int> money;
    money.insert(std::make_pair<int,int>(5,0));
    money.insert(std::make_pair<int,int>(10,0));
    for(auto bill :bills){
      if(bill==5){
        money[5]++;
      }
      else if(bill==10){
        if(money[5]>0){
          money[5]--;
        }
        else{
          std::cout<<money[5]<<std::endl;
          return false;
        }
        money[10]++;
      }
      else{
        if((money[5]>0&&money[10]>0)||(money[5]>=3)){
          money[5]--;
          money[10]--;
        }
        else{
          std::cout<<money[5]<<" "<<money[10]<<std::endl;
          return false;
        }
      }
    }
    return true;
  }
};

int main(){
  Solution s;
  std::vector<int> arr={5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
  s.lemonadeChange(arr);
}