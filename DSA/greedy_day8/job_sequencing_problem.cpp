#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

///Problem Statement:https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
///Solution: : https://www.youtube.com/watch?v=LjPx4wQaRIs&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=47
///Concepts: Greedy
///Complexity: T(n): O(n*n), S(n): O(n) or O(1)

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool comp(pair<int,int> &a, pair<int, int> &b) {
    if(a.first > b.first) return true;
    else if(a.first < b.first) return false;
    else if (a.second > a.second) return true;
    return false;
}
class Solution {
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) {
        vector<int> ans(2,0);
        vector<pair<int, int>> jobs(n);
        vector<bool> slots(n,false);
        for(int i = 0; i < n; i++) {
            jobs[i] = {arr[i].profit, arr[i].dead};
        }
        int selectedNoOfJobs = 0, currTime = 0, maxProfit = 0;
        
        sort(jobs.begin(), jobs.end(), comp);
        
        for(int i = 0; i < n; i++) {
            for(int j = min(n, jobs[i].second) - 1; j >= 0; j--) {
                if(!slots[j]) {
                    maxProfit += jobs[i].first;
                    selectedNoOfJobs++;
                    slots[j] = true;
                    // cout<< jobs[i].first <<"<==sel.\n";
                    break;
                }
                // else 
                //     cout<< jobs[i].first <<"<== not sel.\n";
            }
        }
    
        return ans = {selectedNoOfJobs, maxProfit};
    } 
};
