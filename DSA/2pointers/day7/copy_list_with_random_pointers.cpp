#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

///Problem Statement: https://leetcode.com/problems/copy-list-with-random-pointer/
///Solution: https://www.youtube.com/watch?v=VNf6VynfpdM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=40
///Concepts: 1) Lisked List, Recursion, Iteration -> T(n): O(3n), S(n): O(n)

//Your solution class
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    /// If we can distort original list
    Node* copyRandomList(Node* head) {
        Node * nHead;
        if(!head) return nHead;
        
        Node *temp = head, *dummy = new Node(-1);
        Node * prev = dummy;
        
        // Simple Copying of normal & random pointers
        while(temp){
            Node * nTemp = new Node(temp->val);
            nTemp->random = temp->random;
            
            // Pointing old list random pointer to point to analogous new Node
            temp->random = nTemp;
           
            prev->next = nTemp;
            temp = temp->next;
            prev = prev->next;
        }
        
        nHead = dummy->next;
        Node *nTemp = nHead;
        // reassigning the list's random for new nodes
        nTemp = nHead;
        while(nTemp){
            if(nTemp->random)
                nTemp->random = nTemp->random->random;
            nTemp = nTemp->next;
        }
        
        return nHead;
    }

    /// If we can not distort original list
    Node* copyRandomList(Node* head) {
        Node * nHead;
        if(!head) return nHead;
        // Map for keeping track of mapping of old and new node
        unordered_map<Node *, Node *> m;
        Node *temp = head, *dummy = new Node(-1);
        Node * prev = dummy;
        
        // Simple Copying of normal & random pointers
        while(temp){
            Node * nTemp = new Node(temp->val);
            nTemp->random = temp->random;
            
            // Pointing old list random pointer to point to analogous new Node
            // temp->random = nTemp;
            m[temp] = nTemp;
           
            prev->next = nTemp;
            temp = temp->next;
            prev = prev->next;
        }
        
        nHead = dummy->next;
        
        Node *nTemp = nHead;
        // reassigning the list's random for new nodes
        nTemp = nHead;
        while(nTemp){
            if(nTemp->random)
                nTemp->random = m[nTemp->random];
            nTemp = nTemp->next;
        }
        
        return nHead;
    }
 // Most Efficient
     Node* copyRandomList(Node* head) {
        
        unordered_map<Node*, Node*>data;
        Node *tail = head;
        
        while(tail!=nullptr){
            data[tail] = new Node(tail->val); //tail<->new node mapping
            tail = tail->next;
        }
        
        tail = head;
        while(tail != nullptr){
            data[tail] -> next = data[tail->next];
            data[tail] -> random = data[tail->random];
            tail = tail->next;
        } 
        return data[head];
        
    }
};