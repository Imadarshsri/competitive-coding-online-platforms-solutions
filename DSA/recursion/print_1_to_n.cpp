#include<iostream>
using namespace std;

class Solution {
public:
    void print(int n) {
      if(n == 1){  // Base Condtition
        cout<<"1 "; 
        return;
      }
      print(n - 1); // Hypothesis (on smaller input)
      cout<<n<<" "; // Induction
    }

    void revPrint(int n) {
      if(n == 1){ // Base Condtition
        cout<<"1 "; 
        return;
      }
      cout<<n<<" "; // Induction
      revPrint(n - 1); // Hypothesis (on smaller input)
    }
};


int main(){
  int n = 1;
  cin>>n;
  Solution().print(n);
  cout<<"\n";
  Solution().revPrint(n);
  return 0;
}