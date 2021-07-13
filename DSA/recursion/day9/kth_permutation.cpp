// https://leetcode.com/problems/permutation-sequence/
// O(n^2)
// https://www.youtube.com/watch?v=wT7gcXLYoao&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=56

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kPer(vector<int> &s, string &out, int n, int k, vector<int> &fac){
        
        if(k == 0) {
            for(auto x: s) {
                out.push_back(x + '0');
            }
            return out;
        }
        
        int i = k / fac[n-1];
        out.push_back(s[i] + '0');
        s.erase(s.begin() + i);
        
        return kPer(s, out, n - 1, k % fac[n-1], fac);
    }
    
    string getPermutation(int n, int k) {
        vector<int> fac(n+1, 0);
        fac[0] = 1;
        vector<int> s;
        
        for(int i = 1; i <= n; i++){
            fac[i] = i*fac[i-1];
            s.push_back(i);            
        }
        
        string o;
        return kPer(s, o, n, k-1, fac);
    }
};