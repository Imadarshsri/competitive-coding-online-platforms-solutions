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


Node * searchBST(Node *root, int val) {
   if(root == NULL)
      return NULL;
   else if(root->val == val)
      return root;
   else if(root->val > val)
      return searchBST(root->left, val);

   return searchBST(root->right, val);
}

int inorderPredecessor(Node *root) {
   if(root == NULL) {
      return -1;
   }
   while(root->right != NULL)
      root = root->right;

   return root->val;
}

Node * deleteBST(Node *root, int val) {
   if(root == NULL )
      return NULL;
   else if(root->val > val) {
      root->left = deleteBST(root->left, val);
   }
   else if(root->val < val) {
      root->right = deleteBST(root->right, val);
   }
   else{
      // if leaf
      if(root->left == NULL && root->right == NULL) {
         delete root;
         return NULL;
      }
      else if(root->left == NULL) {
         Node * temp = root->right;
         delete root;
         return temp;
      }
      else if(root->right == NULL) {
         Node * temp = root->left;
         delete root;
         return temp;
      }
      else { // 2 child;
         root->val = inorderPredecessor(root->left);
         root->left = deleteBST(root->left, root->val);
      }
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
   Node *root = new Node(5);
   insertBST(root, 2);
   insertBST(root, 3);
   insertBST(root, 7);
   insertBST(root, 1);
   insertBST(root, -3);
   insertBST(root, 9);


   inorder(root);
   root = deleteBST(root, 5);
   inorder(root);
   root = deleteBST(root, 2);
   inorder(root);
   root = deleteBST(root, 5);
   inorder(root);
   root = deleteBST(root, -3);
   inorder(root);
   cout<<"Data is " << searchBST(root, 3)->val;
}