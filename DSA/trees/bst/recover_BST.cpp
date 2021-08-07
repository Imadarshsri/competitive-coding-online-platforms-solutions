#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left, *right;

   TreeNode (int x) : val(x) {
      left = right = NULL;
   }
};

class Solution {
public:
    TreeNode *a, *b, *prev = new TreeNode(INT_MIN);
    void recoverTreeHelper(TreeNode* root) {
        if(root == nullptr)
            return;
        
        recoverTreeHelper(root->left);
        
        if(a == nullptr && prev->val > root->val) {
            a = prev;
        }
        
        if(a != nullptr && prev->val > root->val) {
            b = root;
        }
        prev = root;
        recoverTreeHelper(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        recoverTreeHelper(root);
        if(a != nullptr) {
            int temp = a->val;
            a->val = b->val;
            b->val = temp;
        }
    }
};