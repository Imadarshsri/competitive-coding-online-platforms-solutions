#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#
///Solution: https://www.youtube.com/watch?v=II6ziNnub1Q&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=46
///Concepts: Greedy
///Complexity: T(n): O(nlogn), S(n): O(n)

class Solution{
    public:
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int>> meets;
        for(int  i = 0; i < n; i++) {
            meets.push_back({end[i], start[i]});
        }
        sort(meets.begin(), meets.end());
        
        int currFinishTime = -1, cnt = 0;
        
        for(auto x: meets) {
            if(x.second > currFinishTime) {
                currFinishTime = x.first;
                cnt++;
            }
        }
        return cnt;
    }
    
};

int main(){
  int n=1;
  scanf("%d",&n);
   int start[n], end[n];
   for(int  i = 0; i < n; i++) {
      cin>>start[i]>>end[i];
   }
   cout<< Solution().maxMeetings(start, end, n);
  return 0;
}