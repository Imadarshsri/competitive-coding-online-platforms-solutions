#include<bits/stdc++.h>
using namespace std;

///Problem Statement: 
///Solution: 
///Concepts: 

//Your solution class
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while(i < j){
          int x = nums[i] + nums[j];
          if(x == target){
              ans.push_back(i);
              ans.push_back(j);
              return ans;
          }
          else if(x < target)
              i++;
          else
              j--;

          cout<<i<<"<->"<<j<<endl;
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
