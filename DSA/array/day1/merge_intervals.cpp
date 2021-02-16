#include<bits/stdc++.h>
using namespace std;
/// Problem: https://leetcode.com/problems/merge-intervals/
/// Solution: https://www.youtube.com/watch?v=2JzRBPFYbKE&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=6

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> temp = intervals[0], temp1 = intervals[0];
        for(auto i = intervals.begin(); i != intervals.end();){
            temp = *i;
            intervals.erase(i);
            for(auto x = i; x != intervals.end(); x++){
                auto inner = *x;
                // cout<<inner[0]<<" <- x0 -- x1-> "<<inner[1]<<endl;
                if(inner[0] <= temp[1]){
                    temp[1] = max(inner[1], temp[1]);
                    temp[0] = min(inner[0], temp[0]);
                    intervals.erase(x);
                    x--;
                    continue;
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
int main(){
  vector<vector<int>> intervals;
  int n;
  cin>>n;
  for(int i = 0; i < n; i++){
    vector <int> temp(2);
    cin>>temp[0]>>temp[1];
    intervals.push_back(temp);
  }
  intervals = Solution().merge(intervals);
  for(auto x : intervals){
      cout<<x[0]<<" "<<x[1]<<", ";
  }
  
}
