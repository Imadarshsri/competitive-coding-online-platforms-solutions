#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/permutation-with-spaces3627/1 
///Solution: https://www.youtube.com/watch?v=1cspuQ6qHW0&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=14
///Concepts: 1) Recursion
// 2) [TODO]??
//Your solution class
class Solution {
public:
    vector<string> permutationWithSpaces(string ip) {
        vector<string> ans;
        string op = "";
        op.push_back(ip[0]);
        ip.erase(ip.begin() + 0);   
        solve(ip, op, ans);
        return ans;
    }
    
    void solve(string ip, string op, vector<string> &ans){
        if(ip.empty()){
            // ans.push_back(op);
            cout<<"("<<op<<")\n";
            return;
        }
        string op1 = op, op2 = op;
        op1.push_back(' ');
        op1.push_back(ip[0]);
        op2.push_back(ip[0]);
        ip.erase(ip.begin() + 0);   
        solve(ip,op1, ans);
        solve(ip,op2, ans);
    }
};

int main(){
  string s;
  cin>>s;
  Solution().permutationWithSpaces(s);
  return 0;
}