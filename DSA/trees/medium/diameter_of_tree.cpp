#include<iostream>
#include<limits.h>
using namespace std;

struct Node {
   int val;
   Node *left, *right;

   Node (int x) : val(x) {
      left = right = NULL;
   }
};


int solve (Node * root, int &res) {
    if(root == nullptr) 
        return 0;
    int lHeight = solve(root->left, res);
    int rHeight = solve(root->right, res);
    int height = max(lHeight, rHeight) + 1;
    int dia = lHeight + rHeight + 1;
    res = max(res, dia);
    return height;
}
int diameterOfTree(Node* root) {
    int res = INT_MIN;
    solve(root, res);
    return res;
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
   root->right->right->right = new Node(7);
   root->right->right->right->right = new Node(8);
   root->right->right->right->right->right = new Node(9);
   root->right->right->right->right->right->right = new Node(10);
   root->right->right->right->right->right->right->right = new Node(11);

   cout<<"Diameter of Tree: " << diameterOfTree(root);
}