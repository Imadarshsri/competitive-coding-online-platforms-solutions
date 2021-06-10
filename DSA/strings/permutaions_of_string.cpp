#include <bits/stdc++.h>
using namespace std;

///Problem Statement: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
///Solution: Watch aditya Verma Video/GFG
///Concepts: Recursion, DP
///Complexity: T(n): O(n!*n) [n -> length of string], S(n): O(n) [recursion stack] 

class Solution {
	public:
	void permute(set<string> &ans, string s, int n, int j) {
	    if(j == n) {
	        ans.insert(s);
	    }
	    
	    for(int i = j; i < n; i++){
	        swap(s[i], s[j]);
	        permute(ans, s, n, j + 1);
	        swap(s[i], s[j]);
	    }
	    
	}
	vector<string>find_permutation(string S) {
	    vector<string> v;
	    set<string> ans;
	    permute(ans, S, S.length(), 0);
	    
	    for(auto x: ans) {
	        v.push_back(x);
	    }
	    return v;
	}
};



int main() {
    int t;
    cin >> t;
    while(t--) {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans) {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}