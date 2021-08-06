#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

#define look(v) cout<< #v << ": "; for(auto x: v) cout << x <<" ";cout<<endl;


struct Node {
   int val;
   Node *left, *right;

   Node (int x) : val(x) {
      left = right = NULL;
   }
};

int shortestPathLength (vector<int> &a, vector<int> &b) {
   unordered_map<int, int> mp; 
   int n = a.size(), m = b.size();
	for(int i = 0; i < n; i++ ) {
		mp[a[i]] = i;
	}
	int j = m-1, idxA = -1;
	for( ; j >= 0; j--) {
		if(mp.find(b[j]) != mp.end()) {
			idxA = mp[b[j]];
         break;
		}	
   }  
   // cout<<j<<"<->"<<idxA<<endl;
	if(idxA != -1)
		return (m - 1 - j) + (n - 1 - idxA);	
	return -1;
}

int findPath(int ele, Node *root, vector<int> &path){
   if(root == nullptr){
      return 0;
   }

   if(root->val == ele){
      path.push_back(ele);
      return 1;
   }

   path.push_back(root->val);
   if(findPath(ele, root->left, path) || findPath(ele, root->right, path))
      return 1;

   if(!path.empty())
      path.pop_back();
   return 0;
}	

// O(n + n + n) // O(n + n + n)
int shortestDistBetweenNodes (Node * root, int a, int b) {
	vector<int> pathA; 
   findPath(a, root, pathA);
	vector<int> pathB; 
   findPath(b, root, pathB);

   look(pathA);
   look(pathB);
   int shortestDist = shortestPathLength(pathA, pathB);
   return shortestDist;
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

   cout<<"Ans: " << shortestDistBetweenNodes(root, 7, 4);
}