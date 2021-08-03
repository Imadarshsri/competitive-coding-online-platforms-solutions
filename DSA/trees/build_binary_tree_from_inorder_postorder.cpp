#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct Node {
   int val;
   Node *left, *right;

   Node (int x) : val(x) {
      left = right = NULL;
   }
};

void inorder(Node * root) {
   if(root == NULL) 
      return;

   inorder(root->left);
   cout << root->val << ", ";
   inorder(root->right);
}

Node * buildTreeFromInorderAndPostOrder(vector<int> &inTree, vector<int> &postTree, int &postIdx, int n, int inStartIdx, int inEndIdx, map<int, int> &mp) {
   if(inStartIdx > inEndIdx) 
      return NULL;   

   postIdx--;

   if(inStartIdx == inEndIdx) {
      return new Node(inTree[inStartIdx]);
   }
   int rootIdx = mp[postTree[postIdx]];
   Node * root = new Node(inTree[rootIdx]);
   root->right = buildTreeFromInorderAndPostOrder(inTree, postTree, postIdx, n, rootIdx + 1, inEndIdx, mp);
   root->left = buildTreeFromInorderAndPostOrder(inTree, postTree, postIdx, n, inStartIdx, rootIdx - 1, mp);
   return root;
}

/*
     1
    / \
   2   3
  /\   /\
 4  5 6  7

*/
int main() {
   int n;
   cin>> n;
   vector<int> inTree(n), postTree(n);
   for(int i = 0; i < n; i++) {
      cin>>postTree[i];
   }
   map<int,int> mp;
   for(int i = 0; i < n; i++) {
      cin>>inTree[i];
      mp[inTree[i]] = i;
   }
   int postIdx = n;
   Node *root = buildTreeFromInorderAndPostOrder(inTree, postTree, postIdx, n, 0, n-1, mp);

   cout<<"Inorder: "; 
   inorder(root);
}