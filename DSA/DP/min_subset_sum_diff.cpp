#include<iostream>
#include<vector>
#include<climits>
using namespace std;

///Problem Statement:https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1#
///Solution: Aditya Verma video
///Concepts: 1) DP: T(N) : O(N*|Sum of all elements of array|), S(N): O(N*|Sum of all elements of array|)

//Macros
#define endl "\n"
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;
class Solution{
	public:
	vector<bool> subsetSumWithGivenSum(int arr[], int n, int arrSum) {
	    vector<vector<bool>> dp(n+1, vector<bool>(arrSum + 1, false));
	    
	    for(int j = 0; j <= arrSum; j++)
	        dp[0][j] = false;
	        
	    for(int i = 0; i <= n; i++) 
	        dp[i][0] = true;
	        
	    for(int i = 1; i <= n; i++) {
	        for(int j = 1; j <= arrSum; j++) { //! what happens if we start from j = 0
	            if(arr[i - 1] <= j) 
	                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];

	            else 
	                dp[i][j] = dp[i - 1][j];
	        }
	    }
	    
	   // for(int i = 0; i <= arrSum; i++) 
	   //     cout<<dp[n][i]<<" ";
	    return dp[n];
	}
	int minSubsetSumWithGivenDiff(int arr[], int n)  { 
	   
	    int ans = INT_MAX, arrSum = 0;
	    for(int i = 0; i < n; i++) {
	        arrSum += arr[i];
	    }
	    vector<bool> v = subsetSumWithGivenSum(arr, n, arrSum);   
	    for(int i = 0; i <= arrSum; i++) {
	        if(v[i] == true)
	            ans = min(ans, abs(arrSum - 2*i));
	    }
	    return ans;
	} 
};


int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i = 0; i <  n; i++){
    cin>>arr[i];
  }
  cout<<Solution().minSubsetSumWithGivenDiff(arr, n);
  return 0;
}