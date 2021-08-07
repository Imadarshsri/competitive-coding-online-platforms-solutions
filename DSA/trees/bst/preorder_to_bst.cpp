#include<iostream>
#include<vector>
using namespace std;
struct Node {
   int val;
   Node *left, *right;

   Node (int x) : val(x) {
      left = right = NULL;
   }
};

// T(n): O(nlogn)
Node * insertBST(Node *root, int val) {
   if(root == NULL)
      return new Node(val);
   else if(root->val > val) {
      root->left = insertBST(root->left, val);
   }
   else {
      root->right = insertBST(root->right, val);
   }
   return root;
}
void inorder(Node * root) {
   if(root == NULL) 
      return;

   inorder(root->left);
   cout << root->val << ", ";
   inorder(root->right);
}
// T(n): O(n^2)
Node *bstFromPreorder(vector<int> &v, int i, int j) {
   if(v.empty() || i > j)
      return NULL;

   Node * root = new Node(v[i]);
   int k = i + 1;
   for(; k <= j && (v[k] < v[i]); k++);

   root->left = bstFromPreorder(v, i+1, k - 1);
   root->right = bstFromPreorder(v, k, j);
   return root;
}
/*
         5
        / \
       2   7
      /\   /\
    1   3 6  9
   /
 -3   
*/
int main() {
   vector<int> preOrder{5, 2, 1, -3, 3, 7, 6, 9};

   // we can use insertBST method
   Node *root = bstFromPreorder(preOrder, 0, preOrder.size() - 1);
   inorder(root);
}