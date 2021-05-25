#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Problem Statement: 
// Solution or Algo: append string a with itself and find b in appended string
// Use strong matching algorithm for solving this.
// TIme Complexity: 
// COMPUTE-PREFIX-FUNCTION runs in Theta(m) time.
// / Pattern Matching runs in O(n)
// Watch this : https://www.youtube.com/watch?v=V5-7GzOfADQ


class Solution {
  vector<int> calculatePrefixTable(string &pat){
    // We wil keep track of longest prefix suffix of pat using lonestPrefixSuffixIndex;
    int longestPrefixSuffixIndex = 0;
    int m = pat.length();
    vector<int> longestPrefixSuffix(m,0);
    longestPrefixSuffix[0] = 0;
    int i = 1;
    while(i < m) {
      // if characters matches 
      if(pat[i] == pat[longestPrefixSuffixIndex]){
        longestPrefixSuffixIndex++;
        longestPrefixSuffix[i] = longestPrefixSuffixIndex;
        i++;
      }
      else{
        // if characters do not match but `longestPrefixSuffixIndex` > 0  i.e. the length of longest prefix is > 0 we can have a valid shift here
        // This is tricky. Consider the example.
        // AAACAAAA and i = 7. The idea is similar
        // to search step.
        if(longestPrefixSuffixIndex != 0){
          longestPrefixSuffixIndex = longestPrefixSuffix[longestPrefixSuffixIndex - 1]; // i.e it can still have the previous longestPS value??
        }
        else{
          longestPrefixSuffix[i] = 0;
          i++;
        }
      }
    }

    return longestPrefixSuffix;
  }

  bool findPatternUsingKMPAlgo(string &text, string &pattern){
    // string pattern, text;
    // pattern = "abacab";
    // text = "abacaabaccabacabaabb";
    // debug(pattern);
    // debug(text);
    vector<int> kmpPrefixTable = calculatePrefixTable(pattern);
    // look(kmpPrefixTable);

    int i = 0, j = 0;
    int n = text.length(), m = pattern.length();
    for(int i = 0; i < n;) {
      if(j == m){
        return true;
        // cout << "Pattern found at shift: " << (i - j);
        j = kmpPrefixTable[j - 1];
      }
      // if chars matches
      if(text[i] == pattern[j]){
        i++;
        j++;
      }
      else{
        // no matched perform a valid shift 
        if(j > 0)
          j = kmpPrefixTable[j - 1];
        else { // when u reach end and not prefix found 
          // j = 0;
          i++;
        }
      }
    }
    return false;
  }

  public: 
  bool isRotation(string &a, string &b){
    return findPatternUsingKMPAlgo(a.append(a), b);
  }
};

int main(){
  string a, b;
  cin>>a>>b;
  if(Solution().isRotation(a,b))
    cout<<"String a is rotation of string b or vice versa.\n";
  else
    cout<<"String a is not a rotation of string b or vice versa.\n";
  return 0;
}