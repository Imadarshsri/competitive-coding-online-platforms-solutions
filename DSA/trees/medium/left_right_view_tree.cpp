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

// T(n): O(n), S(n): O(n)
void viewOfTree(Node* root) {
   if(root == NULL) return;
   // Level Order Traversal
   queue<Node*> q;
   q.push(root);
   cout << "Left View | Right View\n";

   while(!q.empty()) {
      int n = q.size();

      for(auto i = 0; i < n; i++) {
         Node * node = q.front();
         q.pop();
         if(i == 0)
            cout << node->val << " ";

         if(i == n-1)
            cout << node->val << " ";

         if(node->left != NULL)
            q.push(node->left);

         if(node->right != NULL)
            q.push(node->right);
      }

      cout<<endl;
   }
}
// T(n): O(n), S(n): O(1)
void leftViewOfTree(Node* root, int curr, int &maxLevel) {
   if(root == NULL) return;

   if(curr > maxLevel) {
      cout << root->val << " ";
      maxLevel++;
   }

   leftViewOfTree(root->left, curr + 1, maxLevel);
   leftViewOfTree(root->right, curr + 1, maxLevel);
}
// T(n): O(n), S(n): O(1)
void rightViewOfTree(Node* root, int curr, int &maxLevel) {
   if(root == NULL) return;

   if(curr > maxLevel) {
      cout << root->val << " ";
      maxLevel++;
   }

   rightViewOfTree(root->right, curr + 1, maxLevel);
   rightViewOfTree(root->left, curr + 1, maxLevel);
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

   cout<<"View of Tree: \n"; viewOfTree(root);
   int maxLevel = -1;
   cout<<"Left View of Tree: "; leftViewOfTree(root, 0, maxLevel);
   maxLevel = -1;
   cout<<"\nRight View of Tree: "; rightViewOfTree(root, 0, maxLevel);
}