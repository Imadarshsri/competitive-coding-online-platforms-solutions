#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: https://practice.geeksforgeeks.org/problems/subset-sums2234/1#
///Solution: https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=53
///Concepts: Recursion, Bactracking
///Complexity: T(n):  O(2^N), S(n): O(2^N)

class Solution {
public:
    void subSum(vector<int> &arr, int i, int n, vector<int> &ans, int sum) {
        if(i == n){
            ans.push_back(sum);
            return;
        }
        
        subSum(arr, i+1, n, ans, sum);
        subSum(arr, i+1, n, ans, sum + arr[i]);
    }
    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> ans;
        subSum(arr, 0, N, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
} 