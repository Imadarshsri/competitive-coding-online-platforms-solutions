#include<iostream>
#include "../linkedList.cpp"
using namespace std;

///Problem Statement: https://leetcode.com/problems/palindrome-linked-list/
///Solution: https://www.youtube.com/watch?v=-DtNInqFUXs&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=35
///Concepts: 1)Brute: T(n): O(3n/2), S(n): O(n)
// 2) Recursion: T(n): O(n), S(n): O(1)
class Solution {
    ListNode* checkPairNodes(ListNode *p, ListNode *head){
        if(!p) return head;
        ListNode *q = checkPairNodes(p->next, head);
        if(q && p->val == q->val) 
            return q->next;
        else 
            return head;
    }
public:

    // T(n): O(3n/2), S(n): O(n)
    // bool isPalindrome(ListNode* head) {
    //     vector<int> v;
    //     while(head){
    //         v.push_back(head->val);
    //         head = head->next;
    //     }
    //     int n = v.size();
    //     for(int i = 0; i<n/2; i++){
    //         if(v[i] != v[n-i-1]) return false;
    //     }
    //     return true;
    // }
    // T(n): O(n), S(n): O(1)

    bool isPalindrome(ListNode* head) {
        return !(checkPairNodes(head, head));
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
  cout<<"is Plaindrome:"<<Solution().isPalindrome(head);
  return 0;
}