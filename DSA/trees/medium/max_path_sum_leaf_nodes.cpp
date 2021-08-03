#include<bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
 struct Node {
     int data;
     Node *left;
     Node *right;
     Node() : data(0), left(nullptr), right(nullptr) {}
     Node(int x) : data(x), left(nullptr), right(nullptr) {}
     Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
 };


class Solution {
public:
    int solve (Node *root, int &res) {
        if (root == NULL)
            return 0;
            
        if (root->left == NULL && root->right == NULL)
            return root->data;
        
        int l = solve(root->left, res);
        int r = solve(root->right, res);
        int temp = INT_MIN;

        if (root->left == NULL) {
            temp = r + root->data;
        }
        else if (root->right == NULL) {
            temp = l + root->data;
        }
        else {
            temp = max(l,r) + root->data;
            res = max(res,  l + r + root->data);
        }
        return temp;
    }

    int maxPathSum(Node* root) {
        int res = INT_MIN;
        int sum = solve(root, res);
        if(res == INT_MIN) return sum;
        return res;
    }
};