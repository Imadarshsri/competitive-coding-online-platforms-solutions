#include <bits/stdc++.h> 
using namespace std;

///Problem Statement: https://leetcode.com/problems/shortest-common-supersequence/
///Solution: https://www.youtube.com/watch?v=VDhRg-ZJTuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=29
///Concepts: DP, Recursion, LCS
///Complexity: T(n): O(n*m), S(n): O(n*m);[Memoization, Tabulation] n --> Length of str1, m --> Length of str2
///Complexity: T(n): O(2^min(n,m)), S(n): O(min(n,m));[Recursion] n --> Length of str1, m --> Length of str2

//Function to find the length of longest common subsequence in two strings.


class Solution {
public:
    int dp[1005][1005];
    void SCSLength(string str1, string str2, int n, int m) {
        for(int i = 0; i <= n; i++)
            dp[i][0] = i;
        for(int j = 0; j <= m; j++)
            dp[0][j] = j;
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        int i = n, j = m;
        string ans;
        
        SCSLength(str1, str2, n, m);
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans.push_back(str1[i-1]);
                i--; j--;
            }
            else if (dp[i - 1][j] < dp[i][j - 1]) {
                ans.push_back(str1[--i]);
            }
            else {
                ans.push_back(str2[--j]);
            }
        }
        while(i > 0) {
            ans.push_back(str1[--i]);
        }
        while(j > 0) {
            ans.push_back(str2[--j]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution2 {
public:
  string shortestCommonSupersequence(string& A, string& B) {
        int i = 0, j = 0;
        string res = "";
        for (char c : lcs(A, B)) {
            while (A[i] != c)
                res += A[i++];
            while (B[j] != c)
                res += B[j++];
            res += c, i++, j++;
        }
        return res + A.substr(i) + B.substr(j);
    }

    string lcs(string& A, string& B) {
        int n = A.size(), m = B.size();
        vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (A[i] == B[j])
                    dp[i + 1][j + 1] = dp[i][j] + A[i];
                else
                    dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size() ?  dp[i + 1][j] : dp[i][j + 1];
        return dp[n][m];
    }
};

int main(){
   int n = 1, m = 1;
   string s1, s2;
   cin >> n >> m >> s1 >> s2;
   cout << Solution().shortestCommonSupersequence(s1,s2) << endl;
   cout << Solution2().shortestCommonSupersequence(s1,s2) << endl;
   return 0;
}