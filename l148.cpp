//
// Created by hutao on 2020/11/21.
//


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* p1,ListNode* p2){
        ListNode* head=new ListNode(-1);
        ListNode* p=head;
        while (p1&&p2){
            if(p1->val<p2->val){
                p->next=p1;
                p1=p1->next;
            }
            else{
                p->next=p2;
                p2=p2->next;
            }
            p=p->next;
        }
        if(p1){
            p->next=p1;
        }
        if(p2){
            p->next=p2;
        }
        return head->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        if(head->next){
            return head;
        }
        ListNode *slow=head;
        ListNode *fast=head->next;
        while (slow&&fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *l=slow->next;
        slow->next= nullptr;
        auto l1=sortList(head);
        auto l2=sortList(l);
        return merge(l1,l2);
    }
};