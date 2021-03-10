#include<iostream>
#include "../linkedList.cpp"
using namespace std;

///Problem Statement: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
///Solution: https://www.youtube.com/watch?v=Lhu3MsXZy-Q&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=31
///Concepts: 1) two pass using 1 pointer: T(n): O(2n), S(n): O(n) or O(1)
// 2) One Pass using 2 pointers: T(n): O(2n), S(n): O(n)

// Solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // T(n): O(2n), S(n): O(n)
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     vector<int> temp;
    //     ListNode *uHead = new ListNode(INT_MIN);
    //     ListNode *uTail = uHead;
    //     ListNode *tp = head, *ans = head;
    //     while(head){
    //         temp.push_back(head->val);
    //         head = head->next;
    //     }
    //     temp.erase(temp.begin() + temp.size() - n);
    //     for(auto x = 0; x < (temp.size() - n); x++){
    //         // uTail->next = new ListNode(x);
    //         tp = tp->next;
    //     }
    //     tp->next = tp->next->next;
    //     return ans;
    // }
    // T(n): O(n), S(n): O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first = dummy;
        ListNode *second = dummy;
        
        for(int i = 0; i < n; i++){
            first = first->next;
        }
        while(first->next != nullptr){
            first = first->next;
            second = second->next;
        } 
        second->next = second->next->next;
        return dummy->next;
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
  int x = 1;
  cin>>x;
  ListNode *revhead = Solution().removeNthFromEnd(head, x);
  linkedList.display(revhead);
  return 0;
}