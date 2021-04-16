#include<iostream>
#include "../linkedList.cpp"
using namespace std;

///Problem Statement: https://leetcode.com/problems/palindrome-linked-list/
///Solution:  https://www.youtube.com/watch?v=Of0HPkk3JgI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=35
///Concepts: 1) Recursion: T(n): O(2n), S(n): O(1) (ignoring recursion stack size)
class Solution {
public:
    // T(n): O(2n), S(n): O(1) (ignoring recursion stack size)
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || !head) return head;
        int n = 0;
        // Cheecking whether a grp exist or not
        ListNode *t = head;
        while(n < k && t){
            t = t->next;
            n++;
        }
        if(n != k) return head;
        // Reverse grp
        ListNode *x = head, *y = head;
        for(int i = 0; i < k - 1; i++){
            y = x->next;
            x->next = y->next;
            y->next = head;
            head = y;
        }
        x->next = reverseKGroup(x->next, k);
        return head;
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
  int k = 1;
  cin>>k;
  Solution().reverseKGroup(head, k);
  linkedList.display(linkedList.head);
  return 0;
}