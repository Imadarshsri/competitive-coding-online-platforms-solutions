#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;

///Problem Statement: https://leetcode.com/problems/4sum  
///Solution: https://leetcode.com/problems/4sum/solution/ | https://www.youtube.com/watch?v=4ggF3tXIAp0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=20
///Concepts:1) 2 Pointers : T(n): O(n^(k-1)), S(n): O(n)
// 2) 1 pass or 2 pass Hash Map: T(n): O(n^(k-1)), S(n): O(n)
// Follow Up:  K Sum Problem

//Your solution class
class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
      sort(begin(nums), end(nums));
      return kSum(nums, target, 0, 4);
  }
  vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
      vector<vector<int>> res;
      if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
          return res;
      if (k == 2)
          return twoSum(nums, target, start);
      for (int i = start; i < nums.size(); ++i)
          if (i == start || nums[i - 1] != nums[i])
              for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1)) {
                  res.push_back({nums[i]});
                  res.back().insert(end(res.back()), begin(set), end(set));
              }
      return res;
  }
  vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
      vector<vector<int>> res;
      unordered_set<int> s;
      for (auto i = start; i < nums.size(); ++i) {
          if (res.empty() || res.back()[1] != nums[i])
              if (s.count(target - nums[i]))
                  res.push_back({ target - nums[i], nums[i]});
          s.insert(nums[i]);
      }
      return res;
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
  auto ans = Solution().fourSum(nums, target);
  for(auto x: ans) {
    for(auto y: x) cout<<y<<" ";
    cout<<endl;
  }
  return 0;
}
