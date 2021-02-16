#include <iostream>
#include <vector>
/// Problem: https://leetcode.com/problems/find-the-duplicate-number/
/// Solution: https://www.youtube.com/watch?v=32Ll35mhWg0&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=1
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len==2) return nums[0];
        vector<int> v(len);
        for(auto x: nums){
            if(v[x - 1] != 0) return x;
            else v[x-1]++;
        }
        return nums[0];
    }
};


int main(){
  int n = 1;
  cin>>n;
  vector<int> nums(n);

  for(int i = 0; i< n; i++){
    cin>>nums[i];
  }
  cout<<Solution().findDuplicate(nums)<<endl;
  return 0;
}