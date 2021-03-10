#include <iostream>
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

class ListNode {
  public:
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class List{
  public:
  ListNode *head;
  List():head(nullptr){}
  List(ListNode *x) : head(x){}
  // Insert Node
  void insert(ListNode* x){
    ListNode *tail = head;
    while (tail->next != nullptr){
      tail = tail->next;
    }
    tail->next = x;
  }
  // Display Node
  void display(ListNode* head){
    ListNode *curr = head;
    while (curr->next != nullptr){
    std::cout<<curr->val<<" ";
    curr = curr->next;
    }
    std::cout<<std::endl;
  }
};