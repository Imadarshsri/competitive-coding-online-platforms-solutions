#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: Subset Sum Problem https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
///Solution: Aditya Verma Video https://www.youtube.com/watch?v=_gPcYovP7wc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=7
///Concepts: 1) DP: T(N) : O(N*(s1)), S(N): O(N*(s1)) : s1 => (arrSum + diff)/2;

//Macros
#define endl "\n"
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;
class Solution{
public:
  int subsetSum(int arr[], int n, int sum){
    int dp[n+1][sum+1];
    for(int j = 0; j <= sum; j++)
        dp[0][j] = 0;

    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;


    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= sum; j++){ //! what happens if we start from j = 0
        if(arr[i-1] <= j){
          dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i-1][j];
        }
        else{
          dp[i][j] = dp[i-1][j];
        }
      }
    }
    // for(int i = 0; i <= n; i++){
    //   for(int j = 0; j <= sum; j++){
    //       cout<<dp[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }

    return dp[n][sum];
  }
  int countSubsetsWithGivenDiff(int arr[], int n, int diff) {
    int arrSum = 0;
    for(int i = 0; i < n; i++) {
      arrSum += arr[i];
    }

    if(arrSum < diff)
        return 0;
      
    int s1 = (arrSum + diff)/2;
    return subsetSum(arr, n, s1);
  }
};


int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i = 0; i <  n; i++){
    cin>>arr[i];
  }
  int diff = 0;
  cin>>diff;
  cout<<Solution().countSubsetsWithGivenDiff(arr, n, diff);
  return 0;
}