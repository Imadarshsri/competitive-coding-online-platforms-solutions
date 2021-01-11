#include<iostream>
#include<vector>
#include<string>
#include<map>

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
  int n = 0, sprefix = 0, pprefix = 0;
  cin>>n;
  string s,p;
  map<char,int> sc,pc;
  cin >> s >> p;
  for(int i = 0; i < n; i++){
    sc[s[i]]++;
    pc[p[i]]++;
    sprefix += s[i] - '0';
    pprefix += p[i] - '0';
    if(pprefix > sprefix){
       cout<<"No\n";
       return;
    }
  }
  if((sc['0'] == pc['0'] ) && (sc['1'] == pc['1'] ) && (pprefix == sprefix)){
    cout<<"Yes\n";
  }
  else cout<<"No\n";
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