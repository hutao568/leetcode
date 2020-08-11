//
// Created by tao hu on 2020/8/10.
// C++优先队列，先从名字分析，优先队列，对用户看来，它的队头始终是当前队列中的最大值，即为一个大根堆
// 与STL 中的 sort函数比较，sort默认是从小到大排序，而优先队列是从大到小排序
// 所有的STL都是使用()比较的。默认比较使用less（即'<'运算符），如sort(a,a+n)，默认将数组按照递增的顺序来排序（前面的元素<后面的）
// 但是优先队列的源码比较奇特，虽然按道理使用less比较应该默认是小根堆（即堆顶元素最小），但是priority_queue<>默认是大根堆的，
// 这是因为优先队列队首指向最后，队尾指向最前面的缘故！
//

#include<queue>
#include<vector>
#include<iostream>
using namespace std;

struct node
{
  int x, y;
  node(int x,int y):x(x),y(y){}
};

struct cmp
{
  bool operator()(node a,node b)
  {
    if(a.x == b.x)  return a.y >= b.y;
    else return a.x > b.x;
  }
};

bool operator< (node a,node b)
{
  if(a.x == b.x)  return a.y >= b.y;
  else return a.x > b.x;
}


int main()
{
  priority_queue<node> pq;    //带有三个参数的优先队列;
  for(int i = 1; i <= 5; i++)
    for(int j = 1; j <= 5; j++)
      pq.push(node(i,j));
  while(!pq.empty())
  {
    cout<<pq.top().x<<" "<<pq.top().y<<endl;
    pq.pop();
  }
  return 0;
}