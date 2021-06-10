#include <bits/stdc++.h>
using namespace std;

///Problem Statement: https://www.geeksforgeeks.org/print-subsequences-string/
///Solution: Watch aditya Verma Video
///Concepts: Recursion, DP
///Complexity: T(n): O(2 ^ n) [n -> length of string], S(n): O(n) [recursion stack] 


void printAllSubSequences(string &s, int i, string out, set<string> &sub) {
    if(i == s.length()) {
        if(sub.find(out) == sub.end()) 
            sub.insert(out);
        return;
    }
    
    // do no include
    printAllSubSequences(s, i + 1, out, sub);
    
    // include ith character
    out.push_back(s[i]);
    printAllSubSequences(s, i + 1, out, sub);
    
}

int main() {
    string s;
    cin>>s;
    set<string> sub;
    printAllSubSequences(s, 0, "", sub);
    for(auto x: sub){
        cout << x<< " ";
    }
	return 0;
}