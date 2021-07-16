#include<bits/stdc++.h>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1#
///Solution: 
///Concepts: Greedy, Huffman
///Complexity: T(n): O(nlogn + n + n), S(n): O(n + n)

//Your solution class
class Node {
    public:
        int d;
        Node *left, *right;
        Node(int x) : d(x) {
            left = right = nullptr;        
        }
};
class CompareNode {
public: 
   bool operator()(Node *a, Node *b){
      return a->d > b->d;
   }
};

class Solution {
	public:
   void preorder (Node* root, string out, vector<string> &ans) {
      if(root == nullptr || (root->left == nullptr  && root->right == nullptr)) {
         // cout<<out<<", ";
         ans.push_back(out);
      }
      // cout<<"root: "<<root->d<<"\n";
      if(root->left != nullptr) {
         out.push_back('0');
         preorder(root->left, out, ans);
         out.pop_back();
      }
      if(root->right != nullptr) {
         out.push_back('1');
         preorder(root->right, out, ans);
         out.pop_back();
      }
   }
		vector<string> huffmanCodes(string S,vector<int> f,int N) {
		    priority_queue<Node *, vector<Node *>, CompareNode> q;
	        for(auto x: f) {
	            Node *n = new Node(x);
	           // n.left = n.right = nullptr;
	            q.push(n);
	        }
	      //  while(!q.empty()) {
	      //      auto x = q.top();
	      //      cout<< x.d << ", ";
	      //      q.pop();
	      //  }
	       while(q.size() > 1) {
	           auto x = q.top();
	           q.pop();
	           auto y = q.top();
              q.pop();
              Node *parent = new Node(x->d + y->d);
              parent->left = x;
              parent->right = y;
	         //   cout<< "x: " << x->d << "\n";
	         //   cout<< "y: " << y->d << "\n";
	         //   cout<< "p: "<<parent->d << "\n";
              q.push(parent);
	       }
          vector<string> ans;
          preorder(q.top(), "", ans);
	        return ans;   
		}
};

/*
6
abcdef
5 9 12 13 16 45
*/
int main(){
  int n=1;
  scanf("%d",&n);
  string s;
  cin>>s;
  vector<int> f(n);
  for(int i = 0; i < n; i++) {
     cin>>f[i];
  }
  auto v = Solution().huffmanCodes(s, f, n);
  for (auto x: v) {
     cout << x<< ", ";
  }
  return 0;
}