#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: https://leetcode.com/problems/powx-n/
///Solution: https://www.youtube.com/watch?v=l0YC3876qxg&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=14
///Concepts: Binary Exponentiation

//Macros
#define endl "\n"
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;
//Your solution class
class Solution {
public:
  double myPow(double x, int n) {
    if(n==0)
        return 1;
    double ans=myPow(x,n/2);
    
    if(n%2)
        return n<0? (1/x)*ans*ans:x*ans*ans; 
    else
        return ans*ans;       
  }
};

int main(){
  int n=1;
  double x;
  cin>>x>>n;
  cout<<Solution().myPow(x,n);
  return 0;
}
