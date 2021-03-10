#include<iostream>
#include <limits.h>
#include "../linkedList.cpp"
using namespace std;

///Problem Statement: https://leetcode.com/problems/add-two-numbers
///Solution: https://www.youtube.com/watch?v=LBVsXSMOIk4&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=32
///Concepts: 
// 2) 2 Pointers: O(n), S(n): O(n)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans1 = new ListNode(0);
        ListNode *ans = ans1;
        int carry = 0;
        while(l1 && l2){
            int x = l1->val + l2->val + carry;
            ans->next = new ListNode(x%10);
            ans = ans->next;
            carry = x/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int x = l1->val + carry;
            ans->next = new ListNode(x%10);
            ans = ans->next;
            carry = x/10;
            l1 = l1->next;
        }
        
        while(l2){
            int x = l2->val + carry;
            ans->next = new ListNode(x%10);
            ans = ans->next;
            carry = x/10;
            l2 = l2->next;
        }
        if(carry){
            int x =  carry;
            ans->next = new ListNode(x%10);
            ans = ans->next;
        }
        return ans1->next;
    }
};
int main(){
  int n=1;
  scanf("%d",&n);
  List *list1 = new List(), *list2 = new List();
  ListNode *head1, *head2;
  for(int i = 0; i < n; i++){
    int x;
    cin>>x;
    if(head1 == nullptr) list1 = new List(new ListNode(x));
    else{
      ListNode *temp = new ListNode(x);
      list1->insert(temp);
    }
  }
  list1->display(list1->head);

  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    int x;
    cin>>x;
    if(head1 == nullptr) list2 = new List(new ListNode(x));
    else{
      ListNode *temp = new ListNode(x);
      list2->insert(temp);
    }
  }
  list2->display(list2->head);
  ListNode *mergeHead = Solution().addTwoNumbers(head1, head2);
  list2->display(mergeHead);
  return 0;
}