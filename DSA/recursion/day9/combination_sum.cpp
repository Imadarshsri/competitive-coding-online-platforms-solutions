#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

///Problem Statement: https://leetcode.com/problems/combination-sum/
///Solution: https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=50
///Concepts: Recursion, Bactracking, Unbounded Knapsack Pattern
///Complexity: T(n):  O(2^N.klogk), S(n): O(N.2^N) k-> avg length of list across recursion calls


class Solution {
public:
   // As all elements of cands are distinct, we can directly use vector of vectors instead of set of vectors.
    void combSum(vector<int> &cands, vector<int> out, int i, int target, set<vector<int>> &ans){
        if(target == 0) {
            ans.insert(out);
            return;
        }
        if(i == (int)cands.size())
            return;
        
        if(cands[i] <= target) {
            out.push_back(cands[i]);
            combSum(cands, out, i, target - cands[i], ans);
            out.pop_back();
            combSum(cands, out, i + 1, target, ans);
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& cands, int target) {
        set<vector<int>> ans;
        // Sorting is required to ensure all the generated subsets will also be sorted. This helps to identify duplicates.
        sort(cands.begin(), cands.end());
        combSum(cands, {}, 0, target, ans);        
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, target = 0;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        cin>>target;
        Solution ob;
        vector<vector<int>> ans = ob.combinationSum(arr, target);
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