#include<bits/stdc++.h>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#
///Solution: https://www.youtube.com/watch?v=bzXM1Zond9U&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=40
///Concepts: DP, MCM Pattern
///Complexity: T(n): O(n^2), S(n): O(n^2)

// Using 3D array
class Solution{
public:
    int M = 1003;
    unordered_map<string, int> mp;
    int dp[205][205][2];
    int solve(string &s, int i, int j, bool isTrue){
        if(i > j) return false;
        if(i == j){
            if(isTrue) 
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }
        
        if(dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
            
        int ans = 0;
        
        for(int k = i+1; k <= j-1; k+=2) {
            int lT, lF, rT, rF;
            
            if(dp[i][k - 1][true] != -1)
                lT = dp[i][k - 1][true];
            else
                lT = solve(s, i, k - 1, true);
          
            if(dp[i][k - 1][false] != -1)
                lF = dp[i][k - 1][false];
            else
                lF = solve(s, i, k - 1, false);
                
                
            if(dp[k + 1][j][true] != -1)
                rT = dp[k + 1][j][true];
            else
                rT = solve(s, k + 1, j, true);

            
            if(dp[k + 1][j][false] != -1)
                rF = dp[k + 1][j][false];
            else
                rF = solve(s, k + 1, j, false);
            
            
            
            if(s[k] == '&') {
                if(isTrue)
                    ans += ((lT) * (rT)) % M;
                else
                    ans += ((lT * (rF)) % M + ((lF) * (rT) % M) + ((lF) * (rF) % M)) % M;
            }
            else if(s[k] == '|') {
                if(isTrue)
                    ans += (((lT) * (rF)) % M + ((lF) * (rT)) % M + ((lT) * (rT)) % M) % M;
                else
                    ans += ((lF) * (rF)) % M;
            }
            else if(s[k] == '^') {
                if(isTrue)
                    ans += (((lT) * (rF)) % M + ((lF) * (rT)) % M) % M;
                else
                    ans += (((lF) * (rF)) % M + ((lT) * (rT)) % M) % M;
            }
        }
        return dp[i][j][isTrue] = ans % M;
    }
    int countWays(int N, string s){
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, N - 1, true);
    }
};

// Using Map
// class Solution{
// public:
//     int M = 1003;
//     unordered_map<string, int> mp;
//     int solve(string &s, int i, int j, bool isTrue){
//         if(i > j) return false;
//         if(i == j){
//             if(isTrue) 
//                 return s[i] == true;
//             else
//                 return s[i] == false;
//         }
//         string key = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
//         if(mp.find(key) != mp.end())
//             return mp[key];
            
//         int ans = 0;
//         for(int k = i+1; k <= j-1; k+=2) {
//             int lT = solve(s, i, k - 1, true);
//             int lF = solve(s, i, k - 1, false);
//             int rT = solve(s, k + 1, j, true);
//             int rF = solve(s, k + 1, j, false);
            
            
//             if(s[k] == '&') {
//                 if(isTrue)
//                     ans += ((lT % M) * (rT % M)) % M;
//                 else
//                     ans += ((lT % M) * (rF % M)) % M + ((lF  % M) * (rT % M) % M)+ ((lF % M) * (rF % M) % M);
//             }
//             else if(s[k] == '|') {
//                 if(isTrue)
//                     ans += ((lT % M) * (rF % M)) % M + ((lF % M) * (rT % M)) % M + ((lT % M) * (rT % M)) % M;
//                 else
//                     ans += ((lF % M) * (rF % M)) % M;
//             }
//             else if(s[k] == '^') {
//                 if(isTrue)
//                     ans += ((lT % M) * (rF % M)) % M + ((lF % M) * (rT % M)) % M;
//                 else
//                     ans += ((lF % M) * (rF % M)) % M + ((lT % M) * (rT % M)) % M;
//             }
//         }
//         return mp[key] = ans % M;
//     }
//     int countWays(int N, string s){
//         mp.clear();
//         return solve(s, 0, N - 1, true);
//     }
// };

int main(){
  int n=1;
  string s;
  cin>>n>>s;
  cout << Solution().countWays(n, s);
  return 0;
}