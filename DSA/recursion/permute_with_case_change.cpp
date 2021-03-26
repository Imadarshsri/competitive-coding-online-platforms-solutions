#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

///Problem Statement: https://www.geeksforgeeks.org/permute-string-changing-case/
///Solution: https://www.youtube.com/watch?v=J2Er5XceU_I&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=16
///Concepts: 1) Recursion
// 2) [TODO]??
//Your solution class
class Solution {
public:
    vector<string> permutationWithCases(string ip) {
        vector<string> ans;
        transform(ip.begin(), ip.end(), ip.begin(), ::tolower);
        string op = "";
        while(!ip.empty() && (ip[0] >= '0') && (ip[0] <= '9')){
            op.push_back(ip[0]);
            ip.erase(ip.begin() + 0);
        }
        solve(ip, op, ans);
        return ans;
    }
    
    void solve(string ip, string op, vector<string> &ans){
        if(ip.empty()){
            // ans.push_back(op);
            cout<<op<<", ";
            return;
        }
        string op1 = op, op2 = op;
        op1.push_back(ip[0]);
        op2.push_back(ip[0] - 32);
        ip.erase(ip.begin() + 0);  
        solve(ip,op1, ans);
        solve(ip,op2, ans);
    }
};

int main(){
  string s;
  cin>>s;
  Solution().permutationWithCases(s);
  return 0;
}