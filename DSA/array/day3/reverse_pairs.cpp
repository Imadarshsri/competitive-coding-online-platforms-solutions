#include<bits/stdc++.h>
using namespace std;

///Problem Statement: https://leetcode.com/problems/reverse-pairs/
///Solution: https://youtu.be/S6rsAlj_iB4 , https://leetcode.com/problems/two-sum/solution/
///Concepts: 1) Brute Force: O(n^2)
///[TODO:] 2) BST, 3) BIT ?? (Find out)
// 4)Merge Sort: T(n): O(nlogn + n + n) , S(n): O(n)
// nlogn => sorting, n => Merging, n => Counting Reverse pairs
//Macros
#define endl "\n"
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;
//Your solution class
class Solution {
public:
    // Mere Sort
    int merge(vector<int> &nums, int l, int m, int r){
        int i = l, j = m+1;
        int cnt = 0;
        for(; i< m + 1; i++){
            while(j <= r && nums[i] > 2LL*nums[j]){
                j++;
            }
            cnt += j - m - 1;
        }
        // merging
        vector<int> temp(r-l+1);
        int k = 0;
        i = l, j = m+1;
        while(i < m + 1 && j <= r){
            if(nums[i] < nums[j]){
                temp[k++] = nums[i++];
            }
            else if(nums[i] > nums[j]){
                temp[k++] = nums[j++];
            }
            else{
                temp[k++] = nums[i++];
                temp[k++] = nums[j++];
            }
        }
        while(i < m+1){
            temp[k++] = nums[i++];
        }
        
        while(j <= r){
            temp[k++] = nums[j++];
        }
        
        for(int k = 0, i = l; k < (r - l + 1) && i <= r;){
            nums[i++] = temp[k++];
        }
        
        return cnt;
    }
    int mergeSort(vector<int> &nums, int l, int r){
        if(l == r) return 0;
        int invCnt = 0;    
        if(l < r){
            int mid = l + (r-l)/2;
            invCnt += mergeSort(nums, l, mid);
            invCnt += mergeSort(nums, mid + 1, r);
            invCnt += merge(nums, l, mid, r);
        }
        return invCnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};


int main(){
  int n=1;
  scanf("%d",&n);
  vector<int> nums(n);
  for(int i = 0; i < n; i++){
    cin>>nums[i];
  }
  cout<<Solution().reversePairs(nums);
  return 0;
}