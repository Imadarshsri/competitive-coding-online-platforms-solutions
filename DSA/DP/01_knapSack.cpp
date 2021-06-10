#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

/*
Problems based on this pattern:

1. [Subset_sum](./subset_sum.cpp)
2. Equal Sum partition
3. Count of subset with given sum
4. Min. Subset Sum diff.
5. Count of number of subsets with given difference
! 6. Target Sum ???
*/


///Problem Statement: 01 Knapsack Problem
///Solution: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
///Concepts: 1) Recursion : T(n): ??, S(n) : ??
// 2) Memoization DP : T(n): ??, S(n) : ??
// 3) Tabular DP : T(n): ??, S(n) : ??

//Your solution class
// // Recursive Solution: T(n): ??, S(n) : ??
// int knapSack(int W, int wt[], int val[], int n) 
// { 
//   // Base Condition
//   if(n == 0 || W == 0) return 0;
   
//   // Choice Diagram
//   if(wt[n-1] <= W){
//       return max(val[n-1] + knapSack(W - wt[n - 1], wt, val, n-1), knapSack(W, wt, val, n-1));
//   }
//   else{
//       return knapSack(W, wt, val, n-1);
//   }
// }

// // Memoization Solution: T(n): ??, S(n) : ??
// Storage
int dp[1002][1002];
// // Init
// using memeset
// int knapSack(int W, int wt[], int val[], int n) 
// { 
//   // Base Condition
//   if(n == 0 || W == 0) return 0;
   
//   if(dp[n][W] != -1) return dp[n][W];
//   // Choice Diagram
//   if(wt[n-1] <= W){
//       return dp[n][W] = max(val[n-1] + knapSack(W - wt[n - 1], wt, val, n-1), knapSack(W, wt, val, n-1));
//   }
//   else{
//       return dp[n][W] = knapSack(W, wt, val, n-1);
//   }
// }

// Tabular Solution: T(n): ??, S(n) : ??
int knapSack(int W, vector<int> &wt, vector<int> &val, int n) { 
    // Matrix
    int dp[n + 1][W + 1];
    
    // Intialization
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < W + 1; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    
  // Choice Diagram
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < W + 1; j++){
            if(wt[i - 1] <= j){
                dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}


int main(){
  int n=1, W = 1;
  scanf("%d %d",&n, &W);
  vector<int> wt(n), val(n);
  for(int i = 0; i < n; i++){
    cin>>wt[i];
  }

  for(int i = 0; i < n; i++){
    cin>>val[i];
  }

  memset(dp, -1, sizeof(dp));
  cout<< knapSack(W, wt, val, n);
  return 0;
}