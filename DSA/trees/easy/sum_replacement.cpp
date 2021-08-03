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

// 
void sumReplacement(Node * root) {
   if(root == NULL) 
      return;

   sumReplacement(root->left);
   sumReplacement(root->right);

   if(root->left != NULL) 
      root->val += root->left->val;
   if(root->right != NULL) 
      root->val += root->right->val;
}

void inorder(Node * root) {
   if(root == NULL) 
      return;

   inorder(root->left);
   cout << root->val << ", ";
   inorder(root->right);
}
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

   sumReplacement(root);
   cout<<"Inorder: "; 
   inorder(root);
}