#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

///Problem Statement: https://leetcode.com/problems/subsets-ii/
///Solution: https://www.youtube.com/watch?v=RIn3gOkbhQE&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=54
///Concepts: Recursion, Bactracking
///Complexity: 
// Brute: using set T(N): O(2^n(recursion call) + 2^nlog(2^n)(for comparing set and pushing in ans) + NlogN), S(n): O(N.2^N) + O(N) [Recursion stack]
// Discarding duplicates in recursion call itself: T(n):  O(N.2^N), S(n): O(N.2^N) + O(N) [Recursion stack]
// Optimized Subsets Recursive solution for duplicates in array

class Solution {
public:
    // Discarding duplicates in recursion call itself: T(n):  O(N.2^N + NlogN), S(n): O(N.2^N) + O(N) [Recursion stack]
    void _subsetsDup(vector<int>& nums, vector<int> out, int i, vector<vector<int>> &ans) {
        ans.push_back(out);
        for(int j = i; j < nums.size(); j++){
            if(j != i && nums[j] == nums[j-1]) 
                continue;
            out.push_back(nums[j]);
            _subsetsDup(nums, out, j + 1, ans);
            out.pop_back();
        }
    }
    /*
    Here we are iterating thorugh list and generating subsets of legnth l, at level l of recursion call tree hence generating complete lists of subsets without duplicates

    l = 0 -->          (0,{})
                 /       |       \
                /        |        \
    l = 1 --> (1, {1}), (2, {2}), (4, {3})
                |   \
                |    \
l = 2 -> (2, {1, 2}), (4, {1, 3})
    
    ...and so on....
    */
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        // Sorting is required to ensure all the generated subsets will also be sorted. This helps to identify duplicates.
        sort(nums.begin(), nums.end());
        _subsetsDup(nums, {}, 0, ans);
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.subsetsWithDup(arr);
        for(auto v : ans){
            for(auto x : v){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
} 