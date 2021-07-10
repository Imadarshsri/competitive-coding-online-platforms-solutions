#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#
///Solution: https://youtu.be/9uUVFNOT3_Y
///Concepts: DP, MCM Pattern, REcursion, Matrix Chain Multiplication
///Complexity: 
// Recursive T(n): O(n.2^n), S(n): O(n)
// Memoization (Bottom Up) T(n): O(n^3), S(n): O(n*n)
/*
!Bottom Up: Tabulation ???
https://www.radford.edu/~nokie/classes/360/dp-matrix-parens.html
https://www.javatpoint.com/matrix-chain-multiplication-algorithm
*/

class Solution{
public:
    int dp[102][102];

    // int solveBottomUp(int arr[], int n) {
        
    //     int t[n+1][n+1];
        
    //     for(int i = 0; i <= n; i++) {
    //         for(int j = 0; j <= n; j++) {
    //             if(i = 0 || i >= j)
    //                 t[i][j] = 0;
    //         }
    //     }
    //     for(int i = 1; i <= n; i++) {
    //         for(int j = 1; j <= n; j++) {
                
    //             int ans = INT_MAX;
        
    //             for(int k = i; k <= j - 1; k++) {
    //                 int temp_ans = t[i][k] +
    //                               t[k+1][j] +
    //                               (arr[i-1] * arr[k] * arr[j]); ???
                                   
    //                 ans = min(temp_ans, ans);
    //             }
    //             t[i][j] = ans;
    //         }
    //     }
    //     for(int i = 0; i <= n; i++) {
    //         for(int j = 0; j <= n; j++) {
    //             cout<<t[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     return t[1][n];??
    // }
    
    // Recursive T(n): O(n.2^n), S(n): O(n)
    int solveRecursive(int arr[], int i, int j) {
        if(i >= j) 
            return 0;
        
        int ans = INT_MAX;
        
        for(int k = i; k <= j - 1; k++) {
            int temp_ans = solveRecursive(arr, i, k) +
                           solveRecursive(arr, k+1, j) +
                           (arr[i-1] * arr[k] * arr[j]);
                           
            ans = min(temp_ans, ans);
        }
        return ans;
    }
   // Memoization (Bottom Up) T(n): O(n^3), S(n): O(n*n)
    int solveTopDown(int arr[], int i, int j) {
        if(i >= j) 
            return 0;
            
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        
        for(int k = i; k <= j - 1; k++) {
            int temp_ans = solveTopDown(arr, i, k) +
                           solveTopDown(arr, k+1, j) +
                           (arr[i-1] * arr[k] * arr[j]);
                           
            ans = min(temp_ans, ans);
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int n, int arr[]) {
        memset(dp, -1, sizeof(dp));
      //   return solveRecursive(arr, 1, n-1);
        return solveTopDown(arr, 1, n-1);
        // return solveBottomUp(arr, n);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  