#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
///Solution: https://www.youtube.com/watch?v=UmMh7xp07kY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=8
// https://practice.geeksforgeeks.org/viewSol.php?subId=2760991175c9a56cbdef02da5aa3a67f&pid=704573&user=imadarshsri
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

public:
  int equalPartition(int N, int arr[]){
      int sum = 0;
      for(int i = 0; i < N; i++){
          sum += arr[i];
      }
      if(sum & 1) return 0;
      return subsetSum(arr, N, sum/2);
  }
};


int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i = 0; i <  n; i++){
    cin>>arr[i];
  }
  cout<<Solution().equalPartition(n, arr);
  return 0;
}