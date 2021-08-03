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

bool isTreeBalanced(Node * root, int &height) {
   if(root == NULL) {
      height = 0;
      return true;
   }

   int lh = 0, rh = 0;
   if(isTreeBalanced(root->left, lh) && isTreeBalanced(root->right, rh)) {
      height = max(lh, rh) + 1;
      return (abs(lh - rh) <=1);
   }

   return false;
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
   // root->left = new Node(2);
   root->right = new Node(3);
   // root->left->left = new Node(4);
   // root->left->right = new Node(5);
   root->right->left = new Node(6);
   root->right->right = new Node(7);

   int h = 0;
   cout<<"Is tree balanced? "; 
   isTreeBalanced(root, h) ? (cout << "Yes") : (cout << "No");
}