#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: Subset Sum Problem https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
///Solution: https://www.youtube.com/watch?v=_gPcYovP7wc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=7
///Concepts: 1) DP: T(N) : O(N*Sum), S(N): O(N*sum)

//Macros
#define endl "\n"
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;
//Your solution class
class Solution{
public:
  int subsetSum(int arr[], int n, int sum){
    bool dp[n+1][sum+1];
    for(int j = 0; j <= sum; j++)
        dp[0][j] = false;

    for(int i = 0; i <= n; i++)
        dp[i][0] = true;


    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= sum; j++){
        if(arr[i-1] <= j){
          dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i-1][j];
        }
        else{
          dp[i][j] = dp[i-1][j];
        }
      }
    }

    for(int i = 0; i <= n; i++){
      for(int j = 0; j <= sum; j++){
          cout<<dp[i][j]<<" ";
      }
      cout<<"\n";
    }

    return dp[n][sum];
  }
};


int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i = 0; i <  n; i++){
    cin>>arr[i];
  }
  int sum = 0;
  cin>>sum;
  cout<<Solution().subsetSum(arr, n, sum);
  return 0;
}