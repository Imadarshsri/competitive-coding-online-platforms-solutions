#include<bits/stdc++.h>
using namespace std;

///Problem Statement: https://leetcode.com/problems/majority-element
///Solution: https://www.youtube.com/watch?v=AoX3BPWNnoE&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=15
///Concepts: // a) HashMap: T(N): O(N) or O(NlogN), S(N): O(N)
             // b) Boyer Moore's Voting Algo: T(N): O(N) or O(NlogN), S(N): O(N)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int threshold = nums.size()/3;
        set<int> ans;
        int num1 = -1, cnt1 = 0, num2 = -1, cnt2 = 0;
        
        for(auto x: nums){
            if(x == num1) cnt1++;
            else if(x == num2) cnt2++;
            else if(cnt1 == 0){
                num1 = x;
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                num2 = x;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0; cnt2 = 0;
        for(auto x: nums){
            if(x == num1) cnt1++;
            else if(x == num2) cnt2++;
        }
        if(cnt1 > threshold) ans.insert(num1);
        if(cnt2 > threshold) ans.insert(num2);
        return vector<int>(ans.begin(),ans.end());
    }
};
int main(){
  int n=1;
  scanf("%d",&n);
  vector<int> nums(n);
  for(int i = 0; i < n; i++){
    scanf("%d",&nums[i]);
  }
  vector<int> ans = Solution().majorityElement(nums);
  for(int i = 0; i <ans.size(); i++){
    printf("%d ",nums[i]);
  }
  return 0;
}