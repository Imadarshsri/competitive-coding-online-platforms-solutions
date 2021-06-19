#include<iostream>
#include<vector>
#include<climits>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#
///Solution: [Problem similar to this] --> https://www.youtube.com/watch?v=I-l6PBeERuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=16 
///Concepts: DP, Unbounded Knapsack pattern
///Complexity: T(n): O(4*N), S(n): O(4*N) // N --> Length of Line Segment


class Solution {
public: 
    int maximizeTheCuts(int n, int x, int y, int z) {
        
        vector<int> cutLength = {x,y,z};
        int dp[4][n + 1];
        for(int i = 0; i <= 3; i++) {
            dp[i][0] = 0;
        }
        for(int j = 1; j <= n; j++) {
            dp[0][j] = INT_MIN;
        }
        for(int i = 1; i <= 3; i++) {
            for(int j = 1; j <= n; j++) {
                if(cutLength[i-1] <= j) 
                    dp[i][j] = max(1 + dp[i][j - cutLength[i - 1]], dp[i-1][j]);
                    
                else
                    dp[i][j] = dp[i-1][j];
            }
        }        
        if(dp[3][n] <= 0)
            return 0;
        
        return dp[3][n];
    }
    
};
// Problem : Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
// After performing all the cut operations, your `total number of cut segments must be maximum`.
int main() {
  int N = 1, x = 1, y = 1, z = 1; 
  scanf("%d %d %d %d",&N, &x, &y, &z);
  
  cout<< Solution().maximizeTheCuts(N, x, y, z);
  return 0;
}