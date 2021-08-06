#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
///Solution: 
///Concepts: 
///Complexity: T(n): , S(n): 

//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    void flatten(TreeNode* root) {
      if(root == NULL || (root->left == NULL && root->right == NULL)) return;

      flatten(root->left);
      flatten(root->right);

      // If 2 child
      if(root->left != NULL && root->right != NULL) {
         TreeNode * leftTail = root->left;
         TreeNode *rightHead = root->right;

         while(leftTail->right != NULL)
            leftTail = leftTail->right;

         leftTail->right = root->right;
         root->right = root->left;
         root->left = NULL;
      }
      // If only left child
      else if(root->left != NULL) {
         root->right = root->left;
         root->left = NULL;   
      }
    }
};

/*
 
     1
    / \ 
  NULL  3
        /\
      6   7
      /   \ 
      4    5 
      
       1
      / \ 
  NULL   3
         \
         6  
         \   
         4 
         \
         7
         \
         5
 

1 -> 2 -> 3 -> NULL

1-> 2 -> NULL

1-> 3 -> NULL

     1
    / \
   2   3
  /\   /\
 4  5 6  7

*/
int main() {
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->left->right = new TreeNode(5);
   root->right->left = new TreeNode(6);
   root->right->right = new TreeNode(7);

   Solution().flatten(root);
   while(root != NULL) {
      cout<<root->val << " ";
      root = root->right;
   }
}