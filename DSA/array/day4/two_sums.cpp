#include<bits/stdc++.h>
using namespace std;

///Problem Statement: https://leetcode.com/problems/two-sum/
/// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.
///Solution: https://leetcode.com/problems/two-sum/solution/    
///Concepts: 1) Brute: T(n): O(n^2), S(n): O(1)
/// 2) 2 pass hashing: T(n): O(n), S(n): O(n)
/// 3) 1 pass hashing: T(n): O(n), S(n): O(n)

//Your solution class
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> ans;
        int n = nums.size();
        for(auto i = 0; i < n; i++){
            if(m.find(target - nums[i]) != m.end()) {
                // printf("mil gaya: %d %d\n",i,m[target - nums[i]] );                
                ans.push_back(m[target - nums[i]]);
                ans.push_back(i);
            }
            else {
                m.insert({nums[i], i});
                // printf("nahi tha: %d\n",i);                
            }
        }
        return ans;
    }
};
int main(){
  int n=1;
  scanf("%d",&n);
  vector<int> nums(n);
  for(int i = 0; i < n; i++){
    cin>>nums[i];
  }
  int target = 0;
  cin>>target;
  auto ans = Solution().twoSum(nums, target);
  for(auto x: ans) cout<<x<<" ";
  return 0;
}
