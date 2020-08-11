//
// Created by tao hu on 2020/7/6.
//

#include "vector"
#include "iostream"
using namespace std;
class heap{
 public:
  vector<int> arr_;

  heap(vector<int> &arr){
    if(arr.size()>0){
      for(auto num:arr){
        arr_.push_back(num);
      }
      int index=arr.size();
      for(int i=index-1;i>=0;i--){
        adjust(i);
      }
    }
  }

  virtual ~heap(){

  }


  int adjust(int index){
    //调整为大根堆
    int index_l=index*2;
    int index_r=index*2+1;
    int largetIndex=index;
    if(index_l<arr_.size()&&arr_[largetIndex]<arr_[index_l]){
      largetIndex=index_l;
    }
    if(index_r<arr_.size()&&arr_[largetIndex]<arr_[index_r]){
      largetIndex=index_r;
    }
    if(largetIndex!=index){
      int temp=arr_[index];
      arr_[index]=arr_[largetIndex];
      arr_[largetIndex]=temp;
      adjust(largetIndex);
    }
    return largetIndex;
  }

  int top(){
    if(arr_.size())
      return arr_[0];
    return INT_MIN;
  }
  bool pop(){
    if(arr_.size()){
      arr_[0]=arr_[arr_.size()-1];
      arr_.pop_back();
      return 1;
    }
    else{
      return 0;
    }
  }
  void push(int val){
    arr_.push_back(val);
    int last=arr_.size()/2;
    int cur=last;
    while (last!=(cur=adjust(last))){
      last=cur;
    }
  }
  void print(){
    while(arr_.size()){
      cout<<arr_[0]<<" ";
      arr_[0]=arr_[arr_.size()-1];
      arr_.pop_back();
      adjust(0);
    }
    cout<<endl;
  }
};

int main()
{
  vector<int> arr={1,5,7,2,3,1,12,32,67,4,0,-7,-76};
  auto h=heap(arr);
  h.print();
}