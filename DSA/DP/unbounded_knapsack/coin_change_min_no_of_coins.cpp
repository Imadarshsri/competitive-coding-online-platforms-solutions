#include<iostream>
#include<vector>
#include<climits>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1#
///Solution: https://www.youtube.com/watch?v=I-l6PBeERuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=16
///Concepts: DP, Unbounded Knapsack pattern
///Complexity: T(n): O(N*sum), S(n): O(N*sum)
// 1) Recursion : T(n): O(2^N), S(n): O(N)[Recursion Stack]
// 2) Memoization DP : T(n):  O(N*sum), S(n): O(N*sum)
// 3) Tabular DP : T(n): O(N*sum), S(n): O(N*sum)
// [Refer to 01 knapsack or Top down and recursion approach]

class Solution {
public: 	
   int minCoins(int n, int sum, vector<int> &coins) { 
	    int dp[n+1][sum+1];
        for(int j = 0; j <= sum; j++) {
            dp[0][j] = INT_MAX - 1;
        }
        
        for(int i = 1; i <= n; i++) {
            dp[i][0] = 0;
        }
        
        
        for(int j = 1; j <= sum; j++) {
            if(j % coins[0])
                dp[1][j] = INT_MAX - 1;
            else
                dp[1][j] = j/coins[0];
        }
        
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(coins[i - 1] <= j) {
                    dp[i][j] = min((1 + dp[i][j - coins[i-1]]), dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
          
        // for(int i = 0; i <= n; i++) {
        //     for(int j = 0; j <= sum; j++) {
        //         cout<<dp[i][j] << " ";
        //     }
        //     cout<<"\n";
        // }
        
        if((dp[n][sum] == INT_MAX - 1) || (dp[n][sum] == INT_MAX))
            return -1;
            
        return dp[n][sum];
	} };

int main() {
  int n=1, sum = 1;
  scanf("%d %d",&n, &sum);
  vector<int> coins(n);
  for(int i = 0; i < n; i++) {
    cin>>coins[i];
  }

  cout<< Solution().minCoins(n, sum, coins);
  return 0;
}