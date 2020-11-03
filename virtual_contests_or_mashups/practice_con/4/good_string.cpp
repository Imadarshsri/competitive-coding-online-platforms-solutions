#include<iostream>
#include<bits/stdc++.h>

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

void solve(){
  string s;
  cin >> s;
  map <char, int> m;
  int len = s.length();
  if(len < 2) return 0;

  for(int i = 0; i < len; i++) m[s[i]]++;

  if(m.size() == len) return len - 2;

  else if(m.size() ){

  }
  else{
    int ans = 0;
    for(auto x : m) {
      ans = max(ans, len - x);
    }
  }
}

int main(){
  //fastio

  int cases=1;
  //fastscan(cases);
  scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}