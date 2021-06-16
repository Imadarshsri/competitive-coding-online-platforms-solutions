#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1#
///Solution: https://www.youtube.com/watch?v=aycn9KO8_Ls&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=13
///Concepts: DP, Unbounded Knapsack pattern
///Complexity: T(n): O(N*W), S(n): O(N*W)
// 1) Recursion : T(n): O(2^N), S(n): O(N)[Recursion Stack]
// 2) Memoization DP : T(n):  O(N*W), S(n): O(N*W)
// 3) Tabular DP : T(n): O(N*W), S(n): O(N*W)
// [Refer to 01 knapsack or Top down and recursion approach]

class Solution {
public:    
    int unboundedKnapSack(int N, int W,  vector<int> &val, vector<int> &wt) {
        int dp[N+1][W+1];
        
        for(int i = 0; i<=N; i++)
            dp[i][0] = 0;
        for(int j = 0; j <= W; j++)
            dp[0][j] = 0;
        
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= W; j++) {
                if(wt[i-1] <= j)
                    dp[i][j] = max(val[i-1] + dp[i][j - wt[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        // for(int i = 1; i <= N; i++) {
        //     for(int j = 1; j <= W; j++) {
        //       cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return dp[N][W];
    }
    // T(n): O(N*W), S(n): O(W)
    int unboundedKnapSack1D(int N, int W,  vector<int> &val, vector<int> &wt) {
        int dp[W+1];
        
        for(int j = 0; j <= W; j++)
            dp[j] = 0;
        
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= W; j++) {
                if(wt[i-1] <= j)
                    dp[j] = max(val[i-1] + dp[j - wt[i-1]], dp[j]);

                // cout<<dp[j]<<" ";
            }
            // cout<<"\n";
        }   
        return dp[W];
    }
};

int main() {
  int n=1, W = 1;
  scanf("%d %d",&n, &W);
  vector<int> wt(n), val(n);
  for(int i = 0; i < n; i++) {
    cin>>wt[i];
  }

  for(int i = 0; i < n; i++) {
    cin>>val[i];
  }

  cout<< Solution().unboundedKnapSack(n, W, wt, val);
  return 0;
}