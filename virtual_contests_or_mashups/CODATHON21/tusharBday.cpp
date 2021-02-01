#include<iostream>
#include<vector>

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
  int n, nevens = 0, nodds = 0;
  cin>>n;
  vector<int> v(n), pre(n+1);
  pre[0] = 0;
  fo(n){
    cin>>v[i];
    if(v[i]&1){ 
      nodds++;
      pre[i+1] = pre[i] + 1;
    }
    else{
      nevens++;
      pre[i+1] = pre[i];
    }
  }
  ui cnt = 0; 
  look(pre);
  for(int i = 0; i < n; i++){
    if(!(v[i]&1)) cnt++;
    int xr = v[i];
    for(int j = i+1; j < n; j++){
      xr ^= v[j];
      if((xr&1) == 0) cnt++;
    }
  }
  cout<<cnt<<"\n";
}

int main(){
  fastio

  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}