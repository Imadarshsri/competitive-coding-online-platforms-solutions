#include<iostream>
#include<queue>
using namespace std;

struct Node {
   int val;
   Node *left, *right;

   Node (int x) : val(x) {
      left = right = NULL;
   }
};

// 
int heightOfTree(Node * root) {
   if(root == NULL) return 0;

   return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
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

   cout<<"Height of Tree: " << heightOfTree(root);
}