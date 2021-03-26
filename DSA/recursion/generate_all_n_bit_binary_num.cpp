#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1
///Solution: https://www.youtube.com/watch?v=U81n0UYtk98&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=18
///Concepts: 1) Recursion, backtracking

//Your solution class
class Solution{
public:	
    void solve(int n, string op, int ones, int zeros, vector<string> &ans){
        if(n == 0){
            // ans.push_back(op);
            cout<<op<<" ";
            return;
        }
        op.push_back('1');
        solve(n - 1, op, ones + 1, zeros, ans);
        op.pop_back();
        if(zeros < ones){
            op.push_back('0');
            solve(n - 1, op, ones, zeros + 1, ans);
        }
    }
	vector<string> NBitBinary(int n){
	    vector<string> ans;
	    solve(n, "", 0, 0, ans);
	    return ans;
	}
};

int main(){
  int n=1;
  scanf("%d",&n);
  Solution().NBitBinary(n);
  return 0;
}
