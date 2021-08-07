#include<iostream>
#include<vector>
#include<stack>
#include<deque>
using namespace std;
// Sol: 1) Using 2 stacks
// 2) Using deque
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

void inorder(Node * root) {
   if(root == NULL) 
      return;

   inorder(root->left);
   cout << root->val << ", ";
   inorder(root->right);
}
// Using 2 stacks
vector<vector<int>> zigzagLevelOrder(Node* root) {
   if(root == nullptr) return {};
   
   // queue<Node *> q;
   stack<Node *> st, q;
   q.push(root);
   
   vector<vector<int>> ans;
   // vector<int> levelNodes;
   
   while(!q.empty() || !st.empty()) {
      vector<int> levelNodes;
      
      if(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
               Node * node = q.top();
               q.pop();
               cout<< node->val <<" ";
               // levelNodes.push_back(node->val);
               if(node->left != nullptr)
                  st.push(node->left);
               
               if(node->right != nullptr) 
                  st.push(node->right);
            }
      }
      else {
            int n = st.size();
            for(int i = 0; i < n; i++) {
               Node * node = st.top();
               st.pop();
               // levelNodes.push_back(node->val);
               cout<< node->val <<" ";
               if(node->right != nullptr) 
                  q.push(node->right);
               
               if(node->left != nullptr)
                  q.push(node->left);
               
            }
      }
      ans.push_back(levelNodes);
      cout<<endl;
   }
   
   return ans;
}
// Using Deque
vector <int> zigZagTraversal(Node* root) {      
    if(root == NULL) return {};
        
    deque<Node *> q;
    q.push_front(root);
    bool leftToRight = true;
    vector<int> levelNodes;
    while(!q.empty()) {
        int n = q.size();
        if(leftToRight) {
            for(int i = 0; i < n; i++) {
                Node * node = q.front();
                q.pop_front();
                levelNodes.push_back(node->val);
                if(node->left != NULL)
                    q.push_back(node->left);
                
                if(node->right != NULL) 
                    q.push_back(node->right);
            }
        }
        else {
            for(int i = 0; i < n; i++) {
                Node * node = q.back();
                q.pop_back();
                levelNodes.push_back(node->val);
               
                if(node->right != NULL) 
                    q.push_front(node->right);
                
                 if(node->left != NULL)
                    q.push_front(node->left);
                
            }
        }
        leftToRight = !leftToRight;
    }
    
    return levelNodes;
}

/*
         5
        / \
       2   7
      /\    \
    1   3    9
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
   cout<<endl;
   zigzagLevelOrder(root);
}