#include<bits/stdc++.h>
using namespace std;

/// Problem: https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(vector<int> &a, int n){
    int l = 0, s = INT_MIN;
    for(int i = 0; i < n; i++){
        s = max(s, l);
        l += a[i];
        
        if(l < 0) l = 0;
    }
    
    return max(s,l);
}

int main(){
  int n = 1;
  cin>>n;
  vector<int> arr(n);

  for(int i = 0; i< n; i++){
    cin>>arr[i];
  }
  cout<<maxSubarraySum(arr, n)<<endl;
  return 0;
}