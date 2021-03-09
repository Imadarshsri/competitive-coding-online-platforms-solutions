#include<iostream>
#include<vector>
#include<map>
using namespace std;

///Problem Statement: https://www.geeksforgeeks.org/count-number-subarrays-given-xor/
///Solution: https://youtu.be/lO9R5CaGRPY
///Concepts: 1) Brute Force: T(n): O(n^2), S(n): O(1)
          // 2) HashMap: T(n): O(n)( ??), S(n): O(n)

//Your solution class
int solve(vector<int> &A, int k){
  int cnt = 0, xorr = 0;
  map<int,int> freq;

  for(auto x: A){
    xorr = xorr ^ x;

    if(xorr == k) cnt++;

    if(freq.find(xorr ^ k) != freq.end()){
      cnt += freq[xorr ^ k];
    }

    freq[xorr]++;
  }

  return cnt;
}

int main(){
  int n=1;
  scanf("%d",&n);
  vector<int> nums(n);
  for(int i = 0; i < n; i++){
    cin>>nums[i];
  }
  int k = 0;
  cin>>k;
  cout<<solve(nums, k);
  return 0;
}