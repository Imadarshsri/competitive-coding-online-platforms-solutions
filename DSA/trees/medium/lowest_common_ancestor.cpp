#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
///Solution: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/
///Concepts: Recursion, Iteration
///Complexity: T(n): O(n), S(n): O(1)


//  * Definition for a binary tree node.
struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // O(n + n + n) // O(n + n + n)
    Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(root == NULL)
            return root;
        
        if(root->val == p->val || root->val == q->val)
            return root;
        
        Node *left = lowestCommonAncestor(root->left, p, q);
        Node *right = lowestCommonAncestor(root->right, p, q);
        
        if(left != NULL && right != NULL)
            return root;
        
        else if(left == NULL)
            return right;
        
        else return left;
    }
};


/*
     1
    / \
   2   3
  /\   /\
 4  5 6  7

*/
int main() {
   Node *root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   root->left->left = new Node(4);
   root->left->right = new Node(5);
   root->right->left = new Node(6);
   root->right->right = new Node(7);

   cout<<"Ans: " << Solution().lowestCommonAncestor(root, new Node(2), new Node(4))->val;
}