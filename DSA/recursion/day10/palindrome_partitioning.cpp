#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;

///Problem Statement: https://leetcode.com/problems/palindrome-partitioning/
///Solution: https://www.youtube.com/watch?v=WBgsABoClE0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=52
///Concepts: DP, MCM Pattern, Recursion, Palindrome Partitioning
///Complexity: 
// Recursive T(n): O(n.2^n), S(n): O(n)
// Memoization (Bottom Up) T(n): O(n*n!), S(n): O(n*n!)

class Solution {
    bool isPalin(string &s, int i, int j) {
        while(i<j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
public:
    void palinPart(string &s, int idx, vector<string> &out, vector<vector<string>> &ans) {
        int n = s.length();
        if(idx == n) {
            ans.push_back(out);
            return;
        }
        
        for(int k = idx; k < n; k++) {
            if(isPalin(s, idx, k)) {
                out.push_back(s.substr(idx, k - idx + 1));
                palinPart(s, k + 1, out, ans);
                out.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> out;    
        vector<vector<string>> ans;
        palinPart(s, 0, out, ans);
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
      string s;
      cin>>s;      
      Solution ob;
      auto ans = ob.partition(s);
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
