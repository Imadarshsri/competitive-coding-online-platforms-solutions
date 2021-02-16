/// Find the next lexicographical permutation of given array
// If it does not exist return the lowest possible permutation(i.e. sorted array)


#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

// Problem link: https://leetcode.com/problems/next-permutation/
// Solution: https://www.youtube.com/watch?v=LuLCLgMElus&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=9

//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
typedef uint64_t ui;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return;
    
    for(int i = n-2; i >= 0; i--){
        int temp = nums[i];
        int idx = -1;
        for(int j = i + 1; j < n; j++){
            if(nums[j] > temp){
                idx = j;
            }
        }
        
        if(idx != -1){
            nums[i] = nums[idx];
            nums[idx] = temp;
            sort(nums.begin()+i+1, nums.end());
            return;
        }
    }
    
    sort(nums.begin(), nums.end());
    return;
}
void solve(){
  int n = 0;
  cin>>n;
  vector<int> v(n);
  fo(n){
    cin>>v[i];
  }
  nextPermutation(v);
  fo(n){
    cout<<v[i];
  }
}

int main(){
  //fastio

  int cases=1;
  //fastscan(cases);
  scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}