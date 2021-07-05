#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

///Problem Statement:https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
///Solution: https://www.youtube.com/watch?v=dxVcMDI7vyI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=46
///Concepts: Prefix Sum, Overlapping, Greedy
///Complexity: T(n): O(2nlogn) or O(n), S(n): O(n) or O(1)

///  KEY IDEA: We meed top find the max overlapping taking place (as that no. of platforms will be needed) at any instance of time...
class Solution{
    public:
    /*
    It will not work...
    Lets take the example: arr[ ]:  [100, 80, 70, 60] and dept[ ]: [700, 350, 90, 150]
    In this case, your algo will output 4 but the actual output is 3...

    I thought the same algo but performing dry run on some test cases help me understand what's the problem with this algo....i.e. using this we are not keeping track of arrival time of trains on a time frame....which is impacting our overall result.....As striver mentioned in the video we have to keep track of time or we are traversing the time and checking no. of platforms currently occupied....
    Wrong solution bcze we need to keep track of arrival time also so that we can determine at a instance of time no. of trains standing on platform
    */
//    int findPlatform(int arr[], int dep[], int n) {
//         vector<pair<int,int>> trains;
//         priority_queue<int, vector<int>, greater<int>> platforms;
//         for(int i = 0; i < n; i++) 
//             trains.push_back({dep[i], arr[i]});
//         // logic does not sense why sort by dept. ??
//         sort(trains.begin(), trains.end());
//         int earliestDepartureTime = -1;
//         platforms.push(earliestDepartureTime);
//         for(auto x: trains) {
//             earliestDepartureTime = platforms.top();
//             if(earliestDepartureTime < x.second) {
//                 platforms.pop();
//                 platforms.push(x.first);
//             }
//             else {
//                 platforms.push(x.first);
//             }
//         }  
//         return platforms.size();     
//     }

    // Getting Segmentation Fault: ??
    int findPlatform(int arr[], int dep[], int n) {
        int M = 2400, res = 0;
        vector<int> trains(M, 0);
        
        for(int i = 0; i < n; i++) {
            trains[arr[i]]++;
            trains[dep[i]+1]--;
        }        
        
        for(int i = 1; i < M; i++) {
            trains[i] += trains[i - 1];
            res = max(res, trains[i]);
        }
        return res;
    }

    int findPlatform(int arr[], int dep[], int n) {
        sort(arr, arr+n);
        sort(dep, dep+n);
        
        int platforms_needed = 1, res = 1;
        int i = 1, j  =0;
        while(i < n && j < n) {
            if(arr[i] <= dep[j]){
                platforms_needed++;
                i++;
            }
            else{
                platforms_needed--;
                j++;
            }
            
            res = max(res, platforms_needed);
        }
        return res;
    }
};

int main(){
  int n=1;
  scanf("%d",&n);
   int start[n], end[n];
   for(int  i = 0; i < n; i++) {
      cin>>start[i]>>end[i];
   }
   cout<< Solution().findPlatform(start, end, n);
  return 0;
}