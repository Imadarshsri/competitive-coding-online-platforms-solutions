#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
///Solution: https://youtu.be/SZqAQLjDsag
///Concepts: DP, Unbounded Knapsack pattern
///Complexity: T(n): O(L*N), S(n): O(L*N) // N -->  Length of Rod, L-> Size of array of cuts that can be made


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
        for(int i = 0; i <= N; i++) {
            for(int j = 0; j <= W; j++) {
              cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        return dp[N][W];
    }
    // N -->  Length of Rod
    // length --> sizes of cut that rod can cut into 
    // length.size() --> Size of options array for rod cuts given or no. of options for cuts given
    // price --> price corresponding to cut sizes
    // assert(length.size() ==  prices.size())
    int rodCutting(int N, vector<int> &prices, vector<int> &length) {
        return unboundedKnapSack(length.size(), N, prices, length);
    }
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> prices(3,1), length = {x,y,z};
        return rodCutting(n, prices, length);
    }
};

int main() {
  int N = 1, n = 1; // N -> length of Rod, n --> Options of rod cuts array size or no. of options for cutts given
  scanf("%d %d",&N, &n);
  vector<int> prices(n), length(n);
  for(int i = 0; i < n; i++) {
    cin>>length[i];
  }

  for(int i = 0; i < n; i++) {
    cin>>prices[i];
  }

  cout<< Solution().rodCutting(N, prices, length);
  return 0;
}