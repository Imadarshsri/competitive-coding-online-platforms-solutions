#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

///Problem Statement: https://www.interviewbit.com/problems/generate-all-parentheses-ii/#
///Solution: https://www.youtube.com/watch?v=eyCj_u3PoJE&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=17
///Concepts: 1) Recursion, backtracking

//Your solution class
class Solution{
  public:
  // void solve(int n, string op, int openedBrkt, int obCnt, int cbCnt, vector<string> &ans){
  //     if(op.length() == 2*n){
  //         ans.push_back(op);
  //         cout<<op<<"\n";
  //         return;
  //     }
  //     if(openedBrkt == 0 && cbCnt>0 && obCnt > 0){
  //         op.push_back('(');
  //         solve(n, op, openedBrkt + 1, obCnt - 1, cbCnt, ans);
  //     } 
  //     else if(openedBrkt > 0 && obCnt>0 && cbCnt>0){
  //         string op1 = op, op2 = op;
  //         op1.push_back('(');
  //         op2.push_back(')');
  //         solve(n, op1, openedBrkt + 1, obCnt - 1, cbCnt, ans);
  //         solve(n, op2, openedBrkt - 1, obCnt, cbCnt - 1, ans);
  //     }
  //     else if(cbCnt > 0){
  //         op.push_back(')');
  //         solve(n, op, openedBrkt - 1, obCnt, cbCnt - 1, ans);
  //     }
  // }

  vector<string> generateParenthesis(int n) {
      vector<string> ans;
      // solve(n, "", 0, n, n, ans);
      solve(n, "", 0, 0, ans);
      sort(ans.begin(), ans.end());
      return ans;
  }
  void solve(int n, string op, int obCnt, int cbCnt, vector<string> &ans){
      if(obCnt == n && cbCnt == n && op.length() == 2*n){
          cout<<op<<"\n";
          ans.push_back(op);
          return;
      }
      if(obCnt > n || cbCnt > n) return;
      
      if(obCnt < n){
          op.push_back('(');
          solve(n, op, obCnt + 1, cbCnt, ans);
          op.pop_back();
      }
      if(cbCnt < obCnt){
          op.push_back(')');
          solve(n, op, obCnt, cbCnt + 1, ans);
      }
  }

};

int main(){
  int n=1;
  scanf("%d",&n);
  Solution().generateParenthesis(n);
  return 0;
}