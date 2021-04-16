#include<bits/stdc++.h>
using namespace std;

///Problem Statement: https://leetcode.com/problems/top-k-frequent-words
///Solution: https://leetcode.com/problems/top-k-frequent-words/submissions/
///Concepts: 1) Sorting & Hashing: T(N): O(n + nlogN), S(N): O(3n)
/// 2) Heap & Hashing: T(N): O(n + nlogk + k), S(N): O(3n) ??

//Macros
#define endl "\n"
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;
//Your solution class
typedef pair<string, int> PAIR;

bool comp (const PAIR &a, const PAIR &b){
        // if "<" -> a is will on top
        if(a.second == b.second){
            int x = a.first.compare(b.first);
            if(x <= 0) return false;
            else return true;
        }
        else
            return a.second < b.second;
}
class Solution {
public:
    
    struct cmp {
        bool operator()(const PAIR &a, const PAIR &b){
            // if "<" -> a is will on top
            if(a.second == b.second){
                int x = a.first.compare(b.first);
                if(x <= 0) return false;
                else return true;
            }
            else
                return a.second < b.second;
        }
    };
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         unordered_map<string, int> m;
//         for(auto s: words){
//             m[s]++;
//         }
        
//         priority_queue<PAIR, vector<PAIR>, cmp> q(m.begin(), m.end());

//         vector<string> ans;
//         while(k--){
//             auto t = q.top();
//             ans.push_back(t.first);
//             q.pop();
//         }
//         return ans;
//     }
  
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(auto s: words){
            m[s]++;
        }
        vector<PAIR> ans(m.begin(),m.end());
        sort(ans.rbegin(), ans.rend(), comp);
        vector<string> x;
        for(int i = 0; i < k; i++){
            x.push_back(ans[i].first);
        }
        return x;
    }
};

int main(){
  //fastio

  int n=1;
  //fastscan(cases);
  scanf("%d",&n);
  vector<string> v;
  while(n--){
    string s;
    cin>>s;
    v.push_back(s);
  }
  int k;
  cin>>k;
  auto ans = Solution().topKFrequent(v, k);
  look(ans);  
  return 0;
}