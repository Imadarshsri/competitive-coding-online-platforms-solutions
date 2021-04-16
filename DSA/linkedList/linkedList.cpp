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


// 2D LIST
class ListNode2d {
  public:
  int val;
  ListNode2d *next, *bottom;
  ListNode2d() : val(0), next(nullptr), bottom(nullptr) {}
  ListNode2d(int x) : val(x), next(nullptr), bottom(nullptr) {}
  ListNode2d(int x, ListNode2d *next, ListNode2d * bottom) : val(x), next(next), bottom(bottom) {}
};
class List2d{
  public:
  ListNode2d *head;
  List2d():head(nullptr){}
  List2d(ListNode2d *x) : head(x){}
  // Insert Node
  void insertNext(ListNode2d* x){
    ListNode2d *tail = head;
    while (tail->next != nullptr){
      tail = tail->next;
    }
    tail->next = x;
  }

  void insertBottom(ListNode2d* x, int idx){
    ListNode2d *tail = head;

    while (idx--){
      tail = tail->next;
    }
    while (tail->bottom != nullptr){
      tail = tail->bottom;
    }
    tail->bottom = x;
  }
  // Display Node
  void display(ListNode2d* head){
    ListNode2d *curr = head;
    while (curr->next != nullptr){
      
      // std::cout<<curr->val<<" ";
      ListNode2d *nd = curr;
      while (nd->bottom){
        std::cout<<nd->val<<" -> ";
        nd = nd->bottom;
      }
      cout<<"\n|\n";
      curr = curr->next;  
    }
    std::cout<<std::endl;
  }
};