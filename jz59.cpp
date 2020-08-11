//
// Created by tao hu on 2020/7/20.
//

class MaxQueue {
  queue<int> q;
  deque<int> d;
 public:
  MaxQueue() {
  }

  int max_value() {
    if (d.empty())
      return -1;
    return d.front();
  }

  void push_back(int value) {
    while (!d.empty() && d.back() < value) {
      d.pop_back();
    }
    d.push_back(value);
    q.push(value);
  }

  int pop_front() {
    if (q.empty())
      return -1;
    int ans = q.front();
    if (ans == d.front()) {
      d.pop_front();
    }
    q.pop();
    return ans;
  }
};

class MaxQueue {
 public:
  queue<int> data;
  deque<int> helper;
  MaxQueue() {

  }

  int max_value() {
    return helper.empty()?-1:helper.front();
  }

  void push_back(int value) {
    data.push(value);
    while(!helper.empty()&&helper.back()<value){
      helper.pop_back();
    }
    helper.push(value);
  }

  int pop_front() {
    if(data.empty()){
      return -1;
    }
    else{
      int temp=data.front();
      data.pop();
      if(temp==helper.front()){
        helper.pop_front();
      }
      return temp;
    }
  }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */