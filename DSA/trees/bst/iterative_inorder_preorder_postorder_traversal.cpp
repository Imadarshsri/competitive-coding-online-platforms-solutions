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
void preorder(Node * root) {
   if(root == NULL) 
      return;

   cout << root->val << ", ";
   preorder(root->left);
   preorder(root->right);
}

void inorder(Node * root) {
   if(root == NULL) 
      return;

   inorder(root->left);
   cout << root->val << ", ";
   inorder(root->right);
}

void postorder(Node * root) {
   if(root == NULL) 
      return;

   postorder(root->left);
   postorder(root->right);
   cout << root->val << ", ";

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

   cout<<"Inorder: "; 
   inorder(root);
   cout<<"\nPreorder: "; 
   preorder(root);
   cout<<"\nPostorder: ";
   postorder(root);
}