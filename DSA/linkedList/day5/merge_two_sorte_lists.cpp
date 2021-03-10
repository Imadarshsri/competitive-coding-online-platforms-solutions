#include<iostream>
#include <limits.h>
#include "../linkedList.cpp"
using namespace std;

///Problem Statement:https://leetcode.com/problems/merge-two-sorted-lists
///Solution: https://www.youtube.com/watch?v=Xb4slcp1U38&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=28
///Concepts: 1) Brute Force: O(n), S(n): O(n)
// 2) 2 Pointers: O(n), S(n): O(1)
// !Follow up: Merge k sorted lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *mHead = new ListNode(INT_MIN);
        ListNode *mTail = mHead;
        while(l1 && l2){
            if(l1->val < l2->val){
                mTail->next = l1;
                l1 = l1->next;
            }
            else{
                mTail->next = l2;
                l2 = l2->next;
            } 
            mTail = mTail->next;
            mTail->next = nullptr;
        }
        mTail->next = l1 ? l1:l2;
        return mHead->next;
    }
};

int main(){
  int n=1;
  scanf("%d",&n);
  List list1 = List(), list2 = List();
  ListNode *head1, *head2;
  for(int i = 0; i < n; i++){
    int x;
    cin>>x;
    if(head1 == nullptr) list1 = List(new ListNode(x));
    else{
      ListNode *temp = new ListNode(x);
      list1.insert(temp);
    }
  }
  list1.display(list1.head);

  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    int x;
    cin>>x;
    if(head1 == nullptr) list2 = List(new ListNode(x));
    else{
      ListNode *temp = new ListNode(x);
      list2.insert(temp);
    }
  }
  list2.display(list2.head);
  ListNode *mergeHead = Solution().mergeTwoLists(head1, head2);
  list2.display(mergeHead);
  return 0;
}