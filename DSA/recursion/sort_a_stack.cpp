#include<iostream>
#include<stack>
#include<string>
using namespace std;

///Problem Statement: 
///Solution: 
///Concepts: 
//Your solution class
class Solution {
public:
    void insert(stack<int> &s, int temp){
        // showStack(s, "Insert");
        if(s.empty() || (s.top() <= temp)){  // Base Condtition
          s.push(temp);
          return;
        }        
        int x = s.top();  // Induction
        s.pop(); // Induction
        insert(s, temp);  // Hypothesis (on smaller input)
        s.push(x); // Induction
    }

    void showStack(stack<int> s, string str){
        cout<<str<<": ";
        while (!s.empty()){
          cout<<s.top()<<" ";
          s.pop();
        }
        cout<<endl;
    }
    void sortStack(stack<int> &s){
        // showStack(s, "Sort");
        if(s.empty()) return;  // Base Condtition
        int x = s.top();  // Induction
        s.pop();
        sortStack(s); // Hypothesis (on smaller input)
        insert(s, x);  // Induction
    }
};

int main(){
  int n = 1;
  cin>>n;
  stack<int> s;

  for(int i = 0; i< n; i++){
    int  x;
    cin>>x;
    s.push(x);
  }
  Solution().showStack(s, "Intialization");
  Solution().sortStack(s);   
  Solution().showStack(s, "Ans");

  return 0;
}