#include<iostream>
#include <limits.h>
#include "../linkedList.cpp"
using namespace std;

///Problem Statement: https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/
///Solution: https://www.youtube.com/watch?v=u4FWXfgS8jw&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=33
///Concepts: 1)Brute: O(n*m), S(n): O(1)
// 2) 2 Pointers: T(n):??, S(n): O(1)

class Solution {
public:
// T(N): O(m*n), S(N): O(1)
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode *ans;
//         bool flag = 0;
//         while(headA != nullptr){  
//             ListNode *temp = headB;

//             while(temp != nullptr){
//                 if(headA == temp){
//                     ans = temp;
//                     // cout<<"at "<<temp->val<<"\n";
//                     flag = 1;
//                     break;
//                 }
//                 else
//                     // cout<<"Not at "<<temp->val<<"\n";
                
//                 temp = temp->next;
//             }
//             if(flag == 1) break;
//             headA = headA->next;
//         }
//         return ans;
//     }

// ????
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        while(p != q){
            p = (p == nullptr) ? headB : p->next;
            q = (q == nullptr) ? headA : q->next;
        }
        return p;
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
  ListNode *intersectedHead = Solution().getIntersectionNode(head1, head2);
  list2->display(intersectedHead);
  return 0;
}