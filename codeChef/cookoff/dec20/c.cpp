#include<iostream>
#include<vector>
#include<map>
#include<algorithm>


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
  int n = s.size(),twos = 0;
  map<char, int> m; 
  for(auto c: s){
    m[c]++;
  }
  for(auto c : m){
    twos += c.second/2;
  }
  cout<<min(twos,n/3)<<"\n";
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