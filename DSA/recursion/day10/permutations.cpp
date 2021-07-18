#include<bits/stdc++.h>
using namespace std;

///Problem Statement: https://leetcode.com/problems/permutations
///Solution: https://www.youtube.com/watch?v=f2ic2Rsc9pU&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=53
///Concepts: Recursion, Bactracking

///SET: T(n):  O(n.n! + 3logn), S(n): O(N! + 2N) // 3logn -> for insert, erase and find in set
///MAP: T(n):  O(n.n!), S(n): O(N!+ 2N) 
///Optimal Solution: T(n): O(n.n!), S(n): O(N!) //Intution: We are trying for every no. at particular index

class Solution {
public:
    vector<vector<int>> ans;
    // using set
    void permsSet(set<int> nums, vector<int> &v) {
        if(nums.empty()) {
            ans.push_back(v);
        }
        // int n = nums.size();
        for(auto i = nums.begin(); i != nums.end(); i++) {
            int x = *i;
            v.push_back(x);
            nums.erase(i);
            
            permsSet(nums, v);
            
            nums.insert(x);
            v.pop_back();
            
            i = nums.find(x);
        }
    }
     
     // using map
        void permsMap(vector<int> &nums, vector<int> &v, vector<int> &m) {
            if(nums.size() == v.size()) {
                ans.push_back(v);
            }
        int n = nums.size();
        for(auto i = 0; i < n; i++) {
            if(m[i] == 0) {
                v.push_back(nums[i]);
                m[i] = 1;
                permsMap(nums, v, m);
                v.pop_back();
                m[i] = 0;
            }        
        }
    }    
    // using concept of next permutation
    void permsMap(vector<int> &nums, vector<int> &v, vector<int> &m) {
        if(nums.size() == v.size()) {
            ans.push_back(v);
            return;
        }
        int n = nums.size();
        for(auto i = 0; i < n; i++) {
            if(m[i] == 0) {
                v.push_back(nums[i]);
                m[i] = 1;
                permsMap(nums, v, m);
                v.pop_back();
                m[i] = 0;
            }        
        }
    }
    // using swapping to solve this problem
    //Intution: We are trying for every no. at particular index
    void perms(vector<int> &nums, int idx) {
        int n = nums.size();
        if(n == idx) {
            ans.push_back(nums);
            return;
        }
        for(int i = idx; i < n; i++) {
            swap(nums[i], nums[idx]);
            perms(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        set<int> num(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> m(n);
        vector<int> v;
        permsSet(num, v);
        permsMap(nums, v, m);
        perms(nums, 0);
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