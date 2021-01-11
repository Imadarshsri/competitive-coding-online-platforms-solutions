#include<iostream>
#include<vector>
#include<unordered_map>

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
  int n, m, x = 0;
  cin >> n>> m;
  unordered_map<int,int> hash;
  for(int i = 0; i < n+m; i++){
      cin>>x;
      hash[x]++;
  }
  cout<<hash.size()<<endl;
}

int main(){
  //fastio

  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}