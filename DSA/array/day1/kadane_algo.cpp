#include<bits/stdc++.h>
using namespace std;

/// Problem: https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubArray(vector<int>& nums){
    int localSum = 0, globalSum = INT_MIN;
    for(int num: nums){
        localSum += num;
        globalSum = max(globalSum, localSum);

        if(localSum < 0) localSum = 0;
    }
    return globalSum;
}

int main(){
  int n = 1;
  cin>>n;
  vector<int> arr(n);

  for(int i = 0; i< n; i++){
    cin>>arr[i];
  }
  cout<<maxSubArray(arr)<<endl;
  return 0;
}
