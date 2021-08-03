#include <bits/stdc++.h>
using namespace std;
// T(n): O(n*r), S(n): O(n*r)
class Solution{
public:
    int M = 1000000007;
    int dp[1005][1005];
    int solveMemoization(int n, int r) {
        if(r > n) 
            return dp[n][r] = 0;
            
        if(n == r || r == 0) 
            return dp[n][r] = 1;

        if(r == 1)
            return dp[n][r] = n;
        
        if(dp[n][r] != -1)
            return dp[n][r];
        return dp[n][r] = (solveMemoization(n-1, r) % M + solveMemoization(n-1, r-1) % M) % M;
    }   
// T(n): O(n*r), S(n): O(n*r)
    int solveTabulation(int n, int r) {
      int N = 1005;
      vector<vector<int>> dp(N, vector<int>(N, 0));
      for(int i = 0; i <= n; i++) {
         for(int j = 0; j <= r; j++) {
            if(j == 0 || i == j) 
               dp[i][j] = 1;
            else if(j == 1)
               dp[i][j] = i;
         }
      }
      
      for(int i = 1; i <= n; i++) {
         for(int j = 2; j <= r; j++) {
             if(j > i/2) 
                 dp[i][j] = dp[i][i - j];

             else
                dp[i][j] = (dp[i-1][j] % M + dp[i-1][j-1] % M) % M;
         }
      }
     
      return dp[n][r];
    }
     
   // T(n): O(n*r), S(n): O(r)
    
    int nCr(int n, int r){  
        memset(dp, -1, sizeof(dp));
        return solveMemoization(n,r);
        return solveTabulation(n,r);
    }
};