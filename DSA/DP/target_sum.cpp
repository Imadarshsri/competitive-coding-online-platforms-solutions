#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: https://leetcode.com/problems/target-sum/
///Solution: Aditya Verma Video https://www.youtube.com/watch?v=_gPcYovP7wc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=7
///Concepts: 1) DP: T(N) : O(N*(s1)), S(N): O(N*(s1)) : s1 => (arrSum + diff)/2;

//Macros
#define endl "\n"
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;
class Solution {
public:
    
  int subsetSum(vector<int>& arr, int sum){
    int n = arr.size();
    int dp[n+1][sum+1];
    for(int j = 0; j <= sum; j++)
        dp[0][j] = 0;

    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;
    
     dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
      for(int j = 0; j <= sum; j++){ //! why j = 0 ?
        if(arr[i-1] <= j){
          dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i-1][j];
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
  int countSubsetsWithGivenDiff(vector<int>& arr, int diff) {
    int n = arr.size();
    int arrSum = 0;
    for(int i = 0; i < n; i++) {
      arrSum += arr[i];
    }
      

      
    int s1 = (arrSum + diff)/2;
    if((diff&1) != (arrSum&1)) { //! ?????
        return 0;
    }
    return subsetSum(arr, s1);
  }
    int findTargetSumWays(vector<int>& nums, int target) {    
        return countSubsetsWithGivenDiff(nums, target);
    }
};

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i = 0; i <  n; i++){
    cin>>arr[i];
  }
  int diff = 0;
  cin>>diff;
  cout<<Solution().findTargetSumWays(arr, diff);
  return 0;
}