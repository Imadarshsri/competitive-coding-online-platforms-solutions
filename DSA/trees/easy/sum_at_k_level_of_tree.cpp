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
int sumAtKLevel(Node * root, int k) {
   if(root == NULL) 
      return -1;

   if(k == 0)
      return root->val;

   queue<Node *> q;
   q.push(root);
   q.push(NULL);
   int level = 0, sum = 0;

   // cout<< "Level " << ++level << ": ";

   while(!q.empty()) {
      Node *node = q.front();
      q.pop();
      
      if (node == NULL && !q.empty()) {
         level++;
         // cout<< "\nLevel " << ++level << ": ";
         q.push(NULL);
      }
      else if(q.empty()) 
         break;
      
      else {
         if(level == k)
            sum += node->val;

         // cout << node->val << ", ";
         if(node->left != NULL) 
            q.push(node->left);

         if(node->right != NULL) 
            q.push(node->right);
      }
   }
   if(k > level)
      return -1;

   return sum;
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

   int k = 0;
   cin >> k;
   cout<<"Sum: " << sumAtKLevel(root, k);
}