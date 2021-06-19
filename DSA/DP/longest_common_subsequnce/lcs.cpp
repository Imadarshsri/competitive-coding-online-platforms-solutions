#include<iostream>
#include<string>
#include <cstring> 
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
///Solution: https://www.youtube.com/watch?v=4Urd0a0BNng&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=19
///Concepts: DP, Recursion, LCS
///Complexity: T(n): O(n*m), S(n): O(n*m);[Memoization, Tabulation] n --> Length of str1, m --> Length of str2
///Complexity: T(n): O(2^min(n,m)), S(n): O(min(n,m));[Recursion] n --> Length of str1, m --> Length of str2

//Function to find the length of longest common subsequence in two strings.

static int t[1005][1005];
class Solution {
    public:    
    // Recursive T(n): O(2^min(n,m)), S(n): O(min(n,m))
    int lcsRecursive(int x, int y, string X, string Y) {
        if(x == 0 || y == 0)
         return 0;

         if(X[x-1] == Y[y - 1]) 
            return 1 + lcsMemoization(x - 1,y - 1, X, Y);
         else
            return max(lcsMemoization(x - 1,y, X, Y), lcsMemoization(x,y - 1, X, Y));
    }
    // Memoization T(n): O(n*m), S(n): O(n*m)
    int lcsMemoization(int x, int y, string X, string Y) {
        if(x == 0 || y == 0)
         return 0;
          if(t[x][y] != -1)
          return t[x][y];
         if(X[x-1] == Y[y - 1]) 
            return t[x][y] = 1 + lcsMemoization(x - 1,y - 1, X, Y);
         else
            return t[x][y] = max(lcsMemoization(x - 1,y, X, Y), lcsMemoization(x,y - 1, X, Y));
    }
    // Bottom Up T(n): O(n*m), S(n): O(n*m)
    int lcsTabulation(int x, int y, string X, string Y) {
        int dp[x+1][y+1];
        for(int i = 0; i <= x; i++) 
            dp[i][0] = 0;
        for(int j = 0; j <= y; j++) 
            dp[0][j] = 0;
            
        for(int i = 1; i <= x; i++) {
            for(int j = 1; j <= y; j++) {
                if(X[i-1] == Y[j - 1]) 
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[x][y];
    }
};

int main(){
   int n = 1, m = 1;
   string s1, s2;
   cin >> n >> m >> s1 >> s2;
   memset(t, -1, sizeof(t));
   cout << Solution().lcsRecursive(n,m,s1,s2) << endl;
   cout << Solution().lcsMemoization(n,m,s1,s2) << endl;
   cout << Solution().lcsTabulation(n,m,s1,s2) << endl;
   return 0;
}