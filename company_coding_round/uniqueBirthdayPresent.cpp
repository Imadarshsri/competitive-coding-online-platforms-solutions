#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: 
///Solution: 
///Concepts: DP, Recursion
///Complexity: T(n): O(n*k), S(n): O(n.k)

//Your solution class
class Solution {
   public: 
   int M = 10000;
   int solve(int n, int k, int idx, vector<vector<int>> &dp) {
      if (n == 1) 
         return k;
      if (k == 1) 
         return 1;     

      if(dp[k][idx] != -1)
         return dp[k][idx];

      int ans = 0;

      for(int i = idx; i <= n; i += idx)
         ans = ((ans % M) + (solve(n, k - 1, i, dp) % M)) % M;

      return dp[k][idx] = ans % M;
   }
};

int main(){
  int n=1, k;
  scanf("%d%d",&n, &k);
  vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
   cout << Solution().solve(n, k, 1, dp);
  return 0;
}