#include<iostream>
#include "../linkedList.cpp"
using namespace std;

///Problem Statement: https://leetcode.com/problems/delete-node-in-a-linked-list/
///Solution: https://www.youtube.com/watch?v=icnp4FJdZ_c&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=31
///Concepts: 1)Brute: T(n): O(n), S(n): O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *prev = node;
        while(prev->next->next){
            prev->val = prev->next->val;
            prev = prev->next;
        }
        prev->val = prev->next->val;
        prev->next = nullptr;
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
  Solution().deleteNode(head);
  linkedList.display(linkedList.head);
  return 0;
}