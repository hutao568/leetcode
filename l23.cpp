//
// Created by tao hu on 2020/8/10.
//
#include <vector>
#include <queue>
using namespace  std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
      //1.判断7个list是否全空，堆的大小为0
      //2.小根堆对ListNode排序
      //3.出堆后，将该节点后续入堆
      priority_queue<ListNode *> Q;

  }
};