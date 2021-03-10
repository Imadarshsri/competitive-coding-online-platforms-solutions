#include<iostream>
#include "../linkedList.cpp"
using namespace std;

///Problem Statement: https://leetcode.com/problems/middle-of-the-linked-list
///Solution: https://www.youtube.com/watch?v=sGdwSH8RK-o&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=28
///Concepts: 1) Brute Force: O(2n)
// 2) 2 Pointers: O(n)
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *p = head, *q = head;
        while((q != nullptr) && (q->next != nullptr)){
            p = p->next;
            q = q->next->next;
        }
        return p;
    }
};


int main(){
  int n=1;
  scanf("%d",&n);
  List linkedList = List();
  ListNode *head;
  for(int i = 0; i < n; i++){
    int x;
    cin>>x;
    if(head == nullptr) linkedList = List(new ListNode(x));
    else{
      ListNode *temp = new ListNode(x);
      linkedList.insert(temp);
    }
  }
  linkedList.display(linkedList.head);
  ListNode *mid = Solution().middleNode(head);
  linkedList.display(mid);
  return 0;
}