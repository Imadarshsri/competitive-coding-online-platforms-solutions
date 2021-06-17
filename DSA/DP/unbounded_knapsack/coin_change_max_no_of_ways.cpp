#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1#
///Solution: hhttps://www.youtube.com/watch?v=I4UR2T6Ro3w&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=15
///Concepts: DP, Unbounded Knapsack pattern
///Complexity: T(n): O(N*sum), S(n): O(N*sum)
// 1) Recursion : T(n): O(2^N), S(n): O(N)[Recursion Stack]
// 2) Memoization DP : T(n):  O(N*sum), S(n): O(N*sum)
// 3) Tabular DP : T(n): O(N*sum), S(n): O(N*sum)
// [Refer to 01 knapsack or Top down and recursion approach]

class Solution {
public:    
  long long int count(int n, int sum, vector<int> &coins) {
        long long int dp[n+1][sum+1];
        for(int i = 0; i <= sum; i++) {
            dp[0][i] = 0;
        }
        
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(coins[i - 1] <= j) {
                    dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};

int main() {
  int n=1, sum = 1;
  scanf("%d %d",&n, &sum);
  vector<int> coins(n);
  for(int i = 0; i < n; i++) {
    cin>>coins[i];
  }

  cout<< Solution().count(n, sum, coins);
  return 0;
}