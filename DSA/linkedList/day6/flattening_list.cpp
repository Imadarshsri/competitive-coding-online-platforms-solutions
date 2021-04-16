#include<bits/stdc++.h>
#include "../linkedList.cpp"
using namespace std;
// ! THis file only contains the solution of the the problem not the compelete code
///Problem Statement:https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#
///Solution: https://www.youtube.com/watch?v=ysytSSXpAI0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=41
///Concepts: 1) Brute Force -> T(n): O(n*m) , S(n): O(n*m)
// 2) Recursion, Merge Sort -> T(n): O(n*m), S(n):O(1)
// * 2) Recursion, Merge Sort -> T(n): O(n*m), S(n):O(1)
Node * merge(Node *a, Node *b){
    Node *p = a, *q = b, *root = new Node(0);
    Node *ans = root;
    while(p && q){
        if(p->data < q->data){
            ans->bottom = p;
            ans = ans->bottom;
            p = p->bottom;
        }
        else{
            ans->bottom = q;
            ans = ans->bottom;
            q = q->bottom;
        }
    }
    if(p) ans->bottom = p;
    else ans->bottom = q;
    
    return root->bottom;
}
Node *flatten(Node *root) {
    if(!root || root->next == nullptr) 
        return root;
    
    root->next = flatten(root->next);
    
    root = merge(root, root->next);
    
    return root;
}


// we are doing operator overloading through this
// bool operator<(const ListNode2d* & p1, const ListNode2d* & p2)
// {
//     return p1->val< p2->val;
// }

// class compNode{
//     public:
//     // we are doing operator overloading through this
//     bool operator()(Node * p1,  Node *p2){
//         return p1->data > p2->data;
//     }
// };
// *1) T(n): O(N*M), S(n): O(N*m)
// Node *flatten(Node *root) {
//     if(!root) return root;
//     priority_queue <Node *, vector<Node*>, compNode> q;
//     q.push(root);
//     Node *ans;
//     vector<int> v;
//     while(!q.empty()){
//         Node * temp = q.top();
//         // cout<<temp->data<<"\n|\n";
//         q.pop();
        
//         v.push_back(temp->data);
//         if(temp->next) q.push(temp->next);
//         if(temp->bottom) q.push(temp->bottom);
        
//         temp->next = nullptr;
//         temp->bottom = nullptr;
//     }

//     sort(v.begin(), v.end());
//     root = new Node(v[0]);
//     v.erase(v.begin());
//     ans = root;
//     for(auto x: v){
//         ans->bottom = new Node(x);
//         ans = ans->bottom;
//     }
//     return root;
// }

// int main(){
//   int n=1;
//   scanf("%d",&n);
//   List2d linkedList = List2d();
//   ListNode2d *head;
//   for(int i = 0; i < n; i++){
//     int x, opt = 0;
//     cin>>opt>>x;
//     if(head == nullptr) linkedList = List2d(new ListNode2d(x));
//     else if (opt == 1){
//       ListNode2d *temp = new ListNode2d(x);
//       linkedList.insertNext(temp);
//     }
//     else if(opt == 2){
//       int idx = 0;
//       cin>>idx;
//       ListNode2d *temp = new ListNode2d(x);
//       linkedList.insertBottom(temp, idx);
//     }
//   }
//   linkedList.display(linkedList.head);
//   return 0;
// }