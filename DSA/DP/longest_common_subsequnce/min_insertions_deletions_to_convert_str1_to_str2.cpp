#include<iostream>
#include<string>
#include <cstring> 
using namespace std;

///Problem Statement: GGiven two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2.
// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
///Solution: https://www.youtube.com/watch?v=-fx6aDxcWyg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=25
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
    
   // I have exchanged the variable name of n and m for better understanding
	int minOperations(string str1, string str2) { 
	    int n = str1.length(), m = str2.length(), lcs = LCSLength(str1, str2, n, m);
	    return n - lcs + m - lcs;
	}
};
int main(){
   string s1, s2;
   cin >> s1 >> s2;
   cout << Solution().minOperations(s1,s2) << endl;
   return 0;
}