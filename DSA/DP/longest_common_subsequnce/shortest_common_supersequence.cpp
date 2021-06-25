#include<iostream>
#include<string>
#include <cstring> 
using namespace std;

///Problem Statement: Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
// https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
///Solution: https://youtu.be/823Grn4_dCQ
///Concepts: DP, Recursion, LCS
///Complexity: T(n): O(n*m), S(n): O(n*m);[Memoization, Tabulation] n --> Length of str1, m --> Length of str2
///Complexity: T(n): O(2^min(n,m)), S(n): O(min(n,m));[Recursion] n --> Length of str1, m --> Length of str2

//Function to find the length of longest common subsequence in two strings.

static int t[1005][1005];
class MySolution {
    public:    
    // Recursive T(n): O(2^min(n,m)), S(n): O(min(n,m))
    int shortestCommonSupersequenceRecursive(int x, int y, string X, string Y) {
         if(x == 0 || y == 0)        
            return max(x,y);

         if(X[x-1] == Y[y - 1]) 
            return 1 + shortestCommonSupersequenceRecursive(x - 1,y - 1, X, Y);
         else
            return 1 + min(shortestCommonSupersequenceRecursive(x - 1,y, X, Y), shortestCommonSupersequenceRecursive(x,y - 1, X, Y));
    }
    // Memoization T(n): O(n*m), S(n): O(n*m)
    int shortestCommonSupersequenceMemoization(int x, int y, string X, string Y) {
        if(x == 0 || y == 0)
         return max(x,y);
          if(t[x][y] != -1)
          return t[x][y];
         if(X[x-1] == Y[y - 1]) 
            return t[x][y] = 1 + shortestCommonSupersequenceMemoization(x - 1,y - 1, X, Y);
         else
            return t[x][y] = 1 + min(shortestCommonSupersequenceMemoization(x - 1,y, X, Y), shortestCommonSupersequenceMemoization(x,y - 1, X, Y));
    }
    
    // Bottom Up T(n): O(n*m), S(n): O(n*m)   
    int shortestCommonSupersequence(int n, int m, string X, string Y) {
        int dp[n+1][m+1];
        for(int i = 0; i <= n; i++)
            dp[i][0] = i;
            
        for(int j = 0; j <= m; j++)
            dp[0][j] = j;
            
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                if(X[i-1] == Y[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
            
        return dp[n][m];
    }
};


class AdityaVermaSolution {
    public:
    int LCSLength(string X, string Y, int n, int m) {
        int dp[n+1][m+1];
        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;
            
        for(int j = 0; j <= m; j++)
            dp[0][j] = 0;
            
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                if(X[i-1] == Y[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
            
        return dp[n][m];
    }
    // I have exchanged the variable name of n and m for better understanding
    int shortestCommonSupersequence(string X, string Y, int n, int m) {
        return n + m - LCSLength(X, Y, n, m);
    }
};
int main(){
   int n = 1, m = 1;
   string s1, s2;
   cin >> n >> m >> s1 >> s2;
   memset(t, -1, sizeof(t));
   cout << MySolution().shortestCommonSupersequenceRecursive(n,m,s1,s2) << endl;
   cout << MySolution().shortestCommonSupersequenceMemoization(n,m,s1,s2) << endl;
   cout << MySolution().shortestCommonSupersequence(n,m,s1,s2) << endl;
   cout << AdityaVermaSolution().shortestCommonSupersequence(s1,s2, n, m) << endl;
   return 0;
}