#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

///Problem Statement: https://leetcode.com/problems/letter-case-permutation/  
///Solution: https://www.youtube.com/watch?v=4eOPYDOiwFo&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=16
///Concepts: 1) Recursion
// 2) Backtracking
//Your solution class
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        solve(S, "", ans);
        return ans;
    }
    
    void solve(string ip, string op, vector<string> &ans){
        if(ip.empty()){
            ans.push_back(op);
            return;
        }
        if(isalpha(ip[0])){
            string op1 = op, op2 = op;
            op1.push_back(tolower(ip[0]));
            op2.push_back(toupper(ip[0]));
            ip.erase(ip.begin() + 0);
            solve(ip,op1, ans);
            solve(ip,op2, ans);
        }
        else{
            op.push_back(ip[0]);
            ip.erase(ip.begin() + 0);
            solve(ip,op, ans);
        }
    }
};

int main(){
  string s;
  cin>>s;
  Solution().letterCasePermutation(s);
  return 0;
}