#include<iostream>
#include<vector>
#include<string>
using namespace std;

///Problem Statement: https://leetcode.com/problems/longest-substring-without-repeating-characters/
///Solution: https://www.youtube.com/watch?v=qtVh-XEpsJo&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=26
///Concepts: 1) // Brute Force: T(n^2), S(n): O(n)
// 2)  Using Set ad 2 pointers: T(2n), S(n): O(n)
// 3)  Using Map ad 2 pointers: T(n), S(n): O(n)

// class Solution {
// public:
//     // Brute Force: T(n^2), S(n): O(n)
//     int lengthOfLongestSubstring(string s) {
//         int gLen = 0, lLen = 0;
//         int n = s.length();
//         map<char,int> freq;
//         for(int i = 0; i < n; i++){
//             if(freq.find(s[i]) != freq.end()){
//                 gLen = max(gLen, lLen);
//                 i = freq[s[i]] + 1;
//                 freq.clear();
//                 freq[s[i]] = i;
//                 lLen = 1;
//             }
//             else{
//                 freq[s[i]] = i;
//                 lLen++;
//             }
//         }
//         gLen = max(gLen, lLen);
//         return gLen;
//     }
// };

// class Solution {
// public:
//     // Using Set ad 2 pointers: T(2n), S(n): O(n)
//     int lengthOfLongestSubstring(string s) {
//         int gLen = 0, lLen = 0;
//         int n = s.length();
//         set<int> freq;
//         int l = 0, r = 0;
//         while(r < n){
//             while(freq.find(s[r]) != freq.end()){
//                 freq.erase(s[l]);
//                 l++;
//             }
//             freq.insert(s[r]);
            
//             lLen = r - l + 1;
//             gLen = max(gLen, lLen);
//             r++;
//         }
//         return gLen;
//     }
// };

class Solution {
public:
    // Using Map ad 2 pointers: T(n), S(n): O(n)
    int lengthOfLongestSubstring(string s) {
        int gLen = 0;
        int n = s.length();
        vector<int> freq(256,-1);
        int l = 0, r = 0;
        while(r < n){
            if((freq[s[r]] != -1) && (l <= freq[s[r]])){
                l = freq[s[r]] + 1;
            }
            freq[s[r]] = r;
            gLen = max(gLen, r - l + 1);
            r++;
        }
        return gLen;
    }
};

int main(){
  string str;
  cin>>str;
  cout<<Solution().lengthOfLongestSubstring(str)<<endl;
  return 0;
}