#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

///Problem Statement: https://leetcode.com/problems/combination-sum-ii/
///Solution: https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=51
///Concepts: Recursion, Bactracking,  ?? See Leetcode solutions
///Complexity: T(n):  O(2^N.k), S(n): O(2^N.k) --> K: avg legnth of combinations/nums for [recursive calls in] loop
// Optimized Subsets Recursive solution for duplicates in array
class Solution {
public:
    vector<vector<int>> ans;
    void combSum2(vector<int>& cands, vector<int> &out, int i, int target) {
        if(i == cands.size() || target == 0) {
            if(target == 0){
                ans.push_back(out);
            }
            return;            
        }
        int n = cands.size();
        for(int j = i; j < n; j++) {
            if(j != i && cands[j] == cands[j-1]) 
                continue;
            else if(cands[j] <= target) {
                out.push_back(cands[j]);
                combSum2(cands, out, j + 1, target - cands[j]);
                out.pop_back();
            }       
            else
                break;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cands, int target) {
        sort(cands.begin(), cands.end());
        vector<int> out;
        combSum2(cands, out, 0, target);
        return ans;
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
        vector<vector<int>> ans = ob.combinationSum2(arr, target);
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