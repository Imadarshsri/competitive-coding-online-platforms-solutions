#include<iostream>
#include<climits>
using namespace std;

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
    bool checkValidation(TreeNode *root, long int min, long int max) {
        if(root == NULL)
            return true;
        
        if(root->val < max && root->val > min) {
            if((root->left == NULL && root-> right == NULL) || (checkValidation(root->left, min, root->val) && checkValidation(root->right, root->val, max)))
                return true;
            else 
                return false;
        }
        
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return checkValidation(root, LONG_MIN, LONG_MAX);
    }
};