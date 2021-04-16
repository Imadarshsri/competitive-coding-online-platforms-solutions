#include<iostream>
#include "../linkedList.cpp"
using namespace std;

///Problem Statement: https://leetcode.com/problems/linked-list-cycle/
///Solution: https://www.youtube.com/watch?v=354J83hX7RI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=34
///Concepts: 1)Brute: ??
// 2) 2 Pointers: T(n): O(n + 2(x)), S(n): O(1) , x-> length(no of nodes) of cycle
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode *p = head->next, *q = head->next->next;
        while(p && q && p != q && q->next){
            p = p->next;
            q = q->next->next;
        }
        
        if(p && q) return p == q;
        else return false;
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
  cout<<"has Cycle: "<<Solution().hasCycle(head);
  return 0;
}