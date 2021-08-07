#include<iostream>
#include<vector>
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
    TreeNode *buildBST(vector<int> &v, int i, int j) {
        if(i > j)
            return NULL;
        
        int mid = i + (j - i)/2;
        TreeNode *root = new TreeNode(v[mid]);
        
        root->left = buildBST(v, i, mid - 1);
        root->right = buildBST(v, mid + 1, j);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& v) {
        return buildBST(v, 0, v.size()-1);
    }
};