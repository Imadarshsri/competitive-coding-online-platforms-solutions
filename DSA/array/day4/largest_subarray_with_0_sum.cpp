#include<iostream>
#include<vector>
#include<map>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#    
///Solution: https://www.youtube.com/watch?v=xmguZ6GbatA&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=22 
///Concepts: 1) Brute or Two Pointers : T(n): O(n^2), S(n): O(1)
//  2) Hashing : T(n): O(nlogn), S(n): O(n)

// Solution
int maxLen(vector<int> &A, int n) {
    map<int,int> m;
    m[0] = -1;
    int ans = 0, preSum = 0;
    for(int i = 0; i < n; i++){
        preSum += A[i];
        if(m.find(preSum) != m.end()){
            ans = max(ans, i - m[preSum]);
        }
        else{
            m[preSum] = i;
        }
    }
    return ans;
}

int main(){
  int n=1;
  scanf("%d",&n);
  vector<int> nums(n);
  for(int i = 0; i < n; i++){
    cin>>nums[i];
  }
  cout<< maxLen(nums, n);
  return 0;
}