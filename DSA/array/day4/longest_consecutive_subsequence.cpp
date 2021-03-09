#include<iostream>
#include<vector>
#include<set>
using namespace std;

///Problem Statement: https://leetcode.com/problems/longest-consecutive-sequence  
///Solution: https://leetcode.com/problems/longest-consecutive-sequence/solution/
///Concepts: 1) Brute Force: T(n): O(n^2), S(n): O(1)
          // 2) Sorting: T(n): O(nlogn), S(n): O(1)
          // 3) HashSet and Intelligent Sequence Building: T(n): O(n + n), S(n): O(n)
          // [TODO: ]4) Union-Find ALgorithm ??
//Your solution class
// Sorting: T(n): O(nlogn), S(n): O(1)
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();
//         if(n <= 1) return n;
//         sort(nums.begin(), nums.end());
//         int lCon = 1, gCon = 1;
//         for(int i = 1; i < n; i++){
//             if(nums[i] == nums[i-1]) continue;

//             if(nums[i] != (long long int)nums[i - 1] + 1) lCon = 1;
//             else lCon++;
            
//             if(lCon > gCon) gCon = lCon;
//         }
//         return gCon;
//     }
// };

// HashSet and Intelligent Sequence Building: T(n): O(n + n), S(n): O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        set<int> s;
        int lStreak = 0;
        for(auto num: nums) s.insert(num);
        for(auto num: nums){
            if(s.find(num-1) == s.end()){
                int currNum = num;
                int cStreak = 1;
                
                while(s.find(currNum+1) != s.end()){
                    currNum++;
                    cStreak++;
                }
                lStreak = max(lStreak, cStreak);
            }
        }
        return lStreak;
    }
};

// Sorting
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();
//         if(n <= 1) return n;
//         sort(nums.begin(), nums.end());
//         int lCon = 1, gCon = 1;
//         for(int i = 1; i < n; i++){
//             if(nums[i] == nums[i-1]) continue;

//             if(nums[i] != (long long int)nums[i - 1] + 1) lCon = 1;
//             else lCon++;
            
//             if(lCon > gCon) gCon = lCon;
//         }
//         return gCon;
//     }
// };


int main(){
  int n=1;
  scanf("%d",&n);
  vector<int> nums(n);
  for(int i = 0; i < n; i++){
    cin>>nums[i];
  }
  cout<< Solution().longestConsecutive(nums);
  return 0;
}