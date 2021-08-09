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

// In: 4 2 5 1 6 3 7
// Pre: 1 2 4 5 3 6 7


    1
   / \
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