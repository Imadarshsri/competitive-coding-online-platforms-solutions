#include<iostream>
#include<string>
#include <algorithm> 
using namespace std;

///Problem Statement: Given a sequence, find the length of the longest palindromic subsequence in it.
// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
///Solution: https://www.youtube.com/watch?v=wuOOOATz_IA&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=27
///Concepts: DP, Recursion, LCS
///Complexity: T(n): O(n*m), S(n): O(n*m);[Memoization, Tabulation] n --> Length of str1, m --> Length of str2
///Complexity: T(n): O(2^min(n,m)), S(n): O(min(n,m));[Recursion] n --> Length of str1, m --> Length of str2

class Solution {
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
    
    int longestPalindromeSubseq(string s) {
        int n = s.length(), m = n;
        string s2(s);
        reverse(s2.begin(), s2.end());
        // cout<<s<<", "<<s2;
        return LCSLength(s, s2, n, m);
    }
};

int main(){
   string s;
   cin >> s;
   cout << Solution().longestPalindromeSubseq(s) << endl;
   return 0;
}