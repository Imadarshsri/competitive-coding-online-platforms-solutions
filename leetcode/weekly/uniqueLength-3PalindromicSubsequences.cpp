// Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
//  Brute Force:  
// T(n): O(2^n), S(n): O(n)
// Idhar se itna pata chala ki maximum no of palindrome for any character, hume tabhi milega jab uss character k first and last postion ka gap jyada ho, iska matlaba hume agar ek character ka first and last postition mil gaya toh hum ussse generate hone waale palindomes ka count pata kr lenege...I,e # of unique chars between them
// Iska matlab ye h ki hume bas 1st or last position check krni h character ki uske palindromes exist krwane k liye....SO this will me our best optimal solution
    
   // void isPalinSubseq(string s, map<char,int>& ans) {
   //      if(s.length() < 3) 
   //          return;
   //      int res = 0, n = s.length();
        
   //      cout<<s<<endl;
   //      set<char> m;
   //      if(s[0] == s[n-1]){
   //          for(int i = 1; i < n-1; i++){
   //              m.insert(s[i]);
   //          }
   //          cout<<s[0]<<"->"<<(int)m.size()<<endl;
   //          ans[s[0]] = max(ans[s[0]], (int)m.size());
   //          isPalinSubseq(s.substr(1,n-2), ans);
   //      }
   //      else{
   //          isPalinSubseq(s.substr(1), ans);
   //          s.pop_back();
   //          isPalinSubseq(s, ans);
   //      }
   //  }
   //  int countPalindromicSubsequence(string s) {
   //      // memset(dp, -1, sizeof(dp));
   //      map<char,int> ans;
   //      isPalinSubseq(s, ans);
   //      int res = 0;
   //      for(auto x: ans){
   //          res += x.second;
   //      }
   //      return res;
   //  }


   //  Optimal Solution: [Explanation above brute force helper function]  
   // T(n): O(26*n), S(n): O(26*n)
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<pair<int,int>> ans(30, {INT_MAX,-1});
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            ans[idx].first = min(i, ans[idx].first);
            ans[idx].second = i;
        }
        int res = 0;
        for(auto x: ans){
            if(x.first != INT_MAX && x.first != x.second){
                set<char> m;
                for(int i = x.first+1; i < x.second; i++)
                    m.insert(s[i]);
                res += m.size();
            }
        }
        return res;
    }
};