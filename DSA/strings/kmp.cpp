#include<iostream>
#include<vector>
#include<string>

using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define readSeq(v, n) for(int i = 0; i < n; i++) cin>>v[i];
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;

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

void solve(){
  string pattern, text;
  pattern = "abacab";
  text = "abacaabaccabacabaabb";
  vector<int> kmpPrefixTable = calculatePrefixTable(pattern);
  // look(kmpPrefixTable);

  int i = 0, j = 0;
  int n = text.length(), m = pattern.length();
  for(int i = 0; i < n;) {
    if(j == m){
      cout << "Pattern found at shift: " << (i - j);
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


}

int main(){
  solve();
  return 0;
}