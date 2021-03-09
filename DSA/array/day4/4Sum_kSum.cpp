#include<iostream>
#include<algorithm>
#include<vector>
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
        int n = nums.size();
        if(n < 4) return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int t1 = target - nums[i];
            for(int j = i+1; j < n; j++){
                int t2 = t1 - nums[j];
                int x = j + 1, y = n - 1;
                while(x<y){
                    int sum = nums[x] + nums[y];
                    if(sum < t2) x++;
                    else if(sum > t2) y--;
                    else{
                        vector<int> v = {nums[j], nums[x], nums[y]};
                        v.push_back(nums[i]);
                        ans.push_back(v);
                        
                        while (x < y && nums[y] == v[2]) y--;
                    }
                }
                while(j < n - 1 && nums[j] == nums[j+1]) j++;
            }
            while(i < n - 1 && nums[i] == nums[i+1]) i++;
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
  auto ans = Solution().fourSum(nums, target);
  for(auto x: ans) {
    for(auto y: x) cout<<y<<" ";
    cout<<endl;
  }
  return 0;
}
