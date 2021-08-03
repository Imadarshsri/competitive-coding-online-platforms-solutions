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

Node * buildTreeFromInorderAndPreOrder(vector<int> &inTree, vector<int> &preTree, int &preIdx, int n, int inStartIdx, int inEndIdx, map<int, int> &mp) {
   if(inStartIdx > inEndIdx) 
      return NULL;   

   preIdx++;

   if(inStartIdx == inEndIdx) {
      return new Node(inTree[inStartIdx]);
   }
   int rootIdx = mp[preTree[preIdx]];
   Node * root = new Node(inTree[rootIdx]);
   root->left = buildTreeFromInorderAndPreOrder(inTree, preTree, preIdx, n, inStartIdx, rootIdx - 1, mp);
   root->right = buildTreeFromInorderAndPreOrder(inTree, preTree, preIdx, n, rootIdx + 1, inEndIdx, mp);
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
   vector<int> inTree(n), preTree(n);
   for(int i = 0; i < n; i++) {
      cin>>preTree[i];
   }
   map<int,int> mp;
   for(int i = 0; i < n; i++) {
      cin>>inTree[i];
      mp[inTree[i]] = i;
   }
   int preIdx = -1;
   Node *root = buildTreeFromInorderAndPreOrder(inTree, preTree, preIdx, n, 0, n-1, mp);

   cout<<"Inorder: "; 
   inorder(root);
   cout<<"\nPreorder: "; 
   preorder(root);
   cout<<"\nPostorder: ";
   postorder(root);
}