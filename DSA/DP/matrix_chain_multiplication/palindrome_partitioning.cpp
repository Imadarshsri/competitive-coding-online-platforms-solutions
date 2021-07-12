#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
///Solution: https://www.youtube.com/watch?v=szKVpQtBHh8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=37
///Concepts: DP, MCM Pattern, Recursion, Palindrome Partitioning
///Complexity: 
// Recursive T(n): O(n.2^n), S(n): O(n)
// Memoization (Bottom Up) T(n): O(n^3), S(n): O(n*n)
/*
!Bottom Up: Tabulation ???
https://www.radford.edu/~nokie/classes/360/dp-matrix-parens.html
https://www.javatpoint.com/matrix-chain-multiplication-algorithm
*/

class Solution{
   int palin[1002][1002];
   bool isPalindrome(string &s, int i, int j) {
      if(i>=j) return palin[i][j] = 0;

      if(palin[i][j] != -1) 
         return palin[i][j];
      
      for(; i<j; i++, j--){
         if(s[i] != s[j])
            return palin[i][j] = 0;
      }
      return palin[i][j] = 1;
    }
public: 
    // Recursive T(n): O(n.2^n), S(n): O(n)
    int solveRecursive(string &s, int i, int j) {
        if(i >= j || isPalindrome(s, i, j)) 
            return 0;
        
        int ans = INT_MAX;
        
        for(int k = i; k <= j - 1; k++) {
            int temp_ans = solveRecursive(s, i, k) +
                           solveRecursive(s, k+1, j) +
                           1;
                           
            ans = min(temp_ans, ans);
        }
        return ans;
    }

   // Memoization (Top Down) T(n): O(n^3), S(n): O(n*n)
    int solveTopDown(string &s, int i, int j, vector<vector<int>> &dp) {
        if(i >= j) 
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
            
         if(isPalindrome(s, i, j)) 
            return 0;
        
        int ans = INT_MAX;
        
        for(int k = i; k <= j - 1; k++) {
            int temp_ans = solveTopDown(s, i, k, dp) +
                           solveTopDown(s, k+1, j, dp) +
                           1;
                           
            ans = min(temp_ans, ans);
        }
        return dp[i][j] = ans;
    }
    int minPalindromePartition(string &s) {
       int n = s.length();
       memset(palin, -1, sizeof(palin));
       vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
      //   return solveRecursive(s, 0, n-1);
        return solveTopDown(s, 0, n-1, dp);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
      string s;
      cin>>s;      
      Solution ob;
      cout<<ob.minPalindromePartition(s)<<endl;
    }
    return 0;
}  