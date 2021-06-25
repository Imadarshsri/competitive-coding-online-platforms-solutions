#include<iostream>
#include<string>
#include <algorithm> 
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
///Solution: https://www.youtube.com/watch?v=hbTaCmQGqLg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=31   
///Concepts: DP, Recursion, LCS
///Complexity: T(n): O(n*m), S(n): O(n*m);[Memoization, Tabulation] n --> Length of str1, m --> Length of str2
///Complexity: T(n): O(2^min(n,m)), S(n): O(min(n,m));[Recursion] n --> Length of str1, m --> Length of str2

class Solution {
public:
	int LongestRepeatingSubsequence(string X){
		    int n = X.length();
		    int dp[n+1][n+1];
		    for(int i = 0; i <= n; i++){
		        dp[0][i] = 0;
		        dp[i][0] = 0;
		       
		    }
		    for(int i = 1; i <= n; i++) {
		        for(int j = 1; j <= n; j++) {
		          if(i != j && X[i-1] == X[j - 1])   
		                dp[i][j] = 1 + dp[i - 1][j - 1];
		          
		          else
		                dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
		        }
		    }
		    
		    return dp[n][n];
		}
};

int main(){
   string s;
   cin >> s;
   cout << Solution().LongestRepeatingSubsequence(s) << endl;
   return 0;
}