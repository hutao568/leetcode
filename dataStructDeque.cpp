//
// Created by tao hu on 2020/7/20.
//

#include <queue>
#include <stack>
using namespace std;

int main()
{
deque<int> q;
q.push_back(1);
q.push_front(2);
q.pop_back();
q.pop_front();
q.back();
q.front();

queue<int> q1;
q1.push(1);
q1.pop();
q1.front();
q1.back();
}