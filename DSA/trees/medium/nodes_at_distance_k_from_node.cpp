#include<iostream>
#include<vector>
#include<map>
using namespace std;

///Problem Statement: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
///Solution: https://leetcode.com/submissions/detail/534248739/
///Concepts:  DFS , hashMap, 
///Complexity: T(n): O(n), S(n): O(n)

//Macros
#define endl "\n"
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    void findKthNode(TreeNode * root, int k, vector<int> &ans, map<TreeNode *, int> &route) {
        if(root == NULL) 
            return;
        
        if(k == 0) {
            ans.push_back(root->val);
        }
        if(route.find(root->left) == route.end())   
            findKthNode(root->left, k - 1, ans, route);

        if(route.find(root->right) == route.end())   
            findKthNode(root->right, k - 1, ans, route);
    }
    
    bool findPath(TreeNode * root, TreeNode * target, map<TreeNode *, int> &route, int level) {
        if(root == NULL) return false;
        
        pair<TreeNode *, int> p{root, level};
        
        route.insert(p);
        
        if(root == target) {
            return true;
        }
        
        if(findPath(root->left, target, route, level + 1) || findPath(root->right, target, route, level + 1)) {
            return true;
        }
        
        route.erase(root);
        return false;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == NULL || target == NULL)
            return {};
        
        map<TreeNode *, int> route;        
        findPath(root, target, route, 0);
        
        int tarLevel = route[target];
        vector<int> ans;
        for(auto x: route) {
            if(k - abs(tarLevel -  x.second) >= 0)
                findKthNode(x.first, k - abs(tarLevel -  x.second), ans, route);
        }
        
        return ans;
    }
};