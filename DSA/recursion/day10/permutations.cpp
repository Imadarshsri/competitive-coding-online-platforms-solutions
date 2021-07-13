#include<bits/stdc++.h>
using namespace std;

///Problem Statement: https://leetcode.com/problems/permutations
///Solution: https://www.youtube.com/watch?v=f2ic2Rsc9pU&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=53
///Concepts: Recursion, Bactracking
///Complexity: T(n):  O(n!), S(n): O(N!.2N)

class Solution {
public:
    vector<vector<int>> ans;
    void perms(set<int> nums, vector<int> &v) {
        if(nums.empty()) {
            ans.push_back(v);
        }
        // int n = nums.size();
        for(auto i = nums.begin(); i != nums.end(); i++) {
            int x = *i;
            v.push_back(x);
            nums.erase(i);
            
            perms(nums, v);
            
            nums.insert(x);
            v.pop_back();
            
            i = nums.find(x);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        set<int> num(nums.begin(), nums.end());
        vector<int> v;
        perms(num, v);
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
        auto ans = ob.permute(arr);
        for(auto v : ans){
            for(auto x : v){
               cout<< x<<" ";
            }
           cout<<endl;
        }
        cout<<endl;
    }
    return 0;
} 