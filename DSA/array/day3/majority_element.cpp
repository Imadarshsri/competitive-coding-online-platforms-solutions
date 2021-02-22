#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: https://leetcode.com/problems/majority-element
///Solution: https://www.youtube.com/watch?v=AoX3BPWNnoE&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=15
///Concepts: // a) HashMap: T(N): O(N) or O(NlogN), S(N): O(N)
             // b) Moore's Voting Algo: T(N): O(N) or O(NlogN), S(N): O(N)
//Macros
#define endl "\n"
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;
class Solution {
public:
  // a) HashMap: T(N): O(N) or O(NlogN), S(N): O(N)
  // int majorityElement(vector<int>& nums) {
  //     int threshold = nums.size()/2;
  //     map<int,int> m;
  //     for(auto x: nums){
  //         m[x]++;
  //         if(m[x] > threshold) return x;
  //     }
  //     return -1;
  // }
  // b) Moore's Voting Algo: T(N): O(N) or O(NlogN), S(N): O(N)
  int majorityElement(vector<int>& nums) {
      int cnt = 0, ele = 0;
      
      for(auto x: nums){
          if(cnt == 0) ele = x;
          if(ele == x) cnt++;
          else cnt--;
      }
      return ele;
  }
};

int main(){
  int n=1;
  scanf("%d",&n);
  vector<int> nums(n);
  for(int i = 0; i < n; i++){
    cin>>nums[i];
  }
  cout<<Solution().majorityElement(nums)<<"\n";
  return 0;
}