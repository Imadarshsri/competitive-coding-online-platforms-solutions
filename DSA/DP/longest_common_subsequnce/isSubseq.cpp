#include<iostream>
#include<string>
#include <cstring> 
using namespace std;

///Problem Statement: Given 2 strings, Check whether one string is subseq. of other string or not.
///Solution: https://www.youtube.com/watch?v=QVntmksK2es&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=31
///Concepts: DP, Recursion, LCS
///Complexity: T(n): O(n*m), S(n): O(n*m);[Memoization, Tabulation] n --> Length of str1, m --> Length of str2
///Complexity: T(n): O(2^min(n,m)), S(n): O(min(n,m));[Recursion] n --> Length of str1, m --> Length of str2

class Solution {
    public:    
    int isSubseq(int x, int y, string X, string Y) {
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

        return (dp[x][y] == min(x,y)) ? true : false;
    }
};

int main(){
   int n = 1, m = 1;
   string s1, s2;
   cin >> n >> m >> s1 >> s2;
   cout << Solution().isSubseq(n,m,s1,s2) << endl;
   return 0;
}