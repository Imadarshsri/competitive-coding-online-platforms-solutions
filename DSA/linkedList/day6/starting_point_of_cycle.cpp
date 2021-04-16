#include<iostream>
#include "../linkedList.cpp"
using namespace std;

///Problem Statement: https://leetcode.com/problems/linked-list-cycle/
///Solution: https://www.youtube.com/watch?v=354J83hX7RI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=34
///Concepts: 1)Brute Unordered Set : T(n): O(n), S(n): O(n) 
// 2) 2 Pointers: T(n): O(n + 2(x)), S(n): O(1) , x-> length(no of nodes) of cycle
class Solution {
public:
    ListNode * detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode *p = head->next, *q = head->next->next;
        while(p && q && p != q && q->next){
            p = p->next;
            q = q->next->next;
        }
        q = head;
        while(p!=q){
            p = p->next;
            q = q->next;
        }
        if(p && q)
            return p;
        return nullptr;
    }
};

/* T.C = O(n) && S.C = O(n) using unordered_set 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> uset;
        ListNode* curr = head;
        while(curr!=NULL && uset.find(curr)==uset.end()){
            uset.insert(curr);
            curr = curr->next;
        }
        return curr;
    }
};
*/

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
  cout<<"Cycle at: "<<Solution().detectCycle(head)->val;
  return 0;
}