#include<iostream>
#include "../linkedList.cpp"

using namespace std;

///Problem Statement: https://leetcode.com/problems/reverse-linked-list
///Solution: https://www.youtube.com/watch?v=iRtLEoL-r-g&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=27 
///Concepts: 1)Brute Iterative: T(n^2): O(n), S(n): O(n)
// 2) Recursive: T(n): O(n), S(n): O(n)
// 3) Iterative: T(n): O(n), S(n): O(1)

// Solution
class Solution {
public:
    // Recursive: T(n): O(n), S(n): O(n)
    // ListNode* reverseList(ListNode* head) {
    //     if((head == nullptr) || head->next == nullptr) return head;
    //     ListNode * revHead = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = nullptr;
    //     return revHead;
    // }
    // Iterative: T(n): O(n), S(n): O(n)
     ListNode* reverseList(ListNode* head) {
        if((head == nullptr) || head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr  = head;
        while(curr != nullptr){
            ListNode* x = curr->next;
            curr->next = prev;
            prev = curr;
            curr = x;
        }
        return prev;
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
  ListNode *revhead = Solution().reverseList(head);
  linkedList.display(revhead);
  return 0;
}