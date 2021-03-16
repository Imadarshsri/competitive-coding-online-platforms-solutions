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
    int deleteMiddle(stack<int> &s, int n){
        // showStack(s, "Sort", n);
        if(s.empty()){
          if(n&1)
            return (n/2);
          else 
            return (n/2) - 1;
        }  // Base Condtition
        int x = s.top();  // Induction
        s.pop();
        int k = deleteMiddle(s, n + 1); // Hypothesis (on smaller input)

        // showStack(s, "k Sort", k);
        if (k)   // Induction (if we get k here it m   eans this is middle element)
          s.push(x); 
        return k - 1;
    }


    void deleteMiddleWithSizeGiven(stack<int> &s, int k){
        showStack(s, "Sort", k);
        if(s.empty()) return; // Base Condtition

        int x = s.top();  // Induction
        s.pop();
        if(k){   // Induction (if we get k == 0 means this is middle element)
          deleteMiddleWithSizeGiven(s, k - 1); // Hypothesis (on smaller input)
          s.push(x); 
        }    
    }


    void showStack(stack<int> s, string str, int n){
        cout<<str<<" "<<n<<": ";
        while (!s.empty()){
          cout<<s.top()<<" ";
          s.pop();
        }
        cout<<endl;
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
  Solution().showStack(s, "Intialization", -1);
  // Solution().deleteMiddle(s, 0);   
  Solution().deleteMiddleWithSizeGiven(s, s.size()/2);   
  Solution().showStack(s, "Ans", -1);

  return 0;
}