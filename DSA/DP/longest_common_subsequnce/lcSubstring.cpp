#include<iostream>
#include<string>
#include <cstring> 
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
///Solution:https://www.youtube.com/watch?v=HrybPYpOvz0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=22
///Concepts: DP, Recursion, LCS
///Complexity: T(n): O(n*m), S(n): O(n*m);[Memoization, Tabulation] n --> Length of str1, m --> Length of str2
///Complexity: T(n): O(2^min(n,m)), S(n): O(min(n,m));[Recursion] n --> Length of str1, m --> Length of str2

class Solution {
    public:    
    int longestCommonSubstr (string S1, string S2, int n, int m) {
        /*
        t[i][j] --> Represents the common substring length including the ith character of X & jth char. of Y, when X.length() is considered as `i` && Y.length() is considered as `j`.
        t[i][j] --> Commmon suffix Length (when X has initial i chars & Y has initial j chars)
        */
        int t[n+1][m+1];
        for(int i = 0; i <= n; i++)
            t[i][0] = 0;
        for(int j = 0; j <= m; j++)
            t[0][j] = 0;
            
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                if(S1[i - 1] == S2[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = 0;
            }
            
        int ans = 0;
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                    ans = max(ans,t[i][j]);
                    
        
        return ans;
    }
};

int main(){
   int n = 1, m = 1;
   string s1, s2;
   cin >> n >> m >> s1 >> s2;
   cout << Solution().longestCommonSubstr(s1,s2, n,m) << endl;
}