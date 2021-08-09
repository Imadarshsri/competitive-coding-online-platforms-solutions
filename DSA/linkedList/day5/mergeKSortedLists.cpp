#include<iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:    
    void print(ListNode *head) {
        ListNode* t=head;
        while(t != nullptr) {
            cout <<t->val << " ";
            t = t->next;
        }
        cout << endl;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * dummy = new ListNode(), *tr = dummy;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                tr->next = l1;
                l1 = l1->next;
                tr = tr->next;
                tr->next = nullptr;
            }
            else {
                tr->next = l2;
                l2 = l2->next;
                tr = tr->next;
                tr->next = nullptr;
            }
        }
        if(l1 != nullptr) {
            tr->next = l1;
        }
        else {
            tr->next = l2;
        }
        
        return dummy->next;
    }
    
    ListNode* mergeLists(vector<ListNode*>& lists, int i, int j) {
        if(j < i)
            return nullptr;
        if(i == j)
            return lists[i];
        
        int mid = i + (j-i)/2;
        ListNode *head1 = mergeLists(lists, i, mid);
        ListNode *head2 = mergeLists(lists, mid + 1, j);
        return mergeTwoLists(head1, head2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return mergeLists(lists, 0, n-1);
    }
};