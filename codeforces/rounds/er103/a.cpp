#include<iostream>
#include<vector>
#include<math.h>

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
  int n, k;
  cin>>n>>k;
  if(k >= n){
    cout<<ceil(k/(n*1.0))<<"\n";
  }
  else if(n%k == 0){
    cout<<ceil(k*(n/k)/(n*1.0))<<"\n";
  }
  else{
    cout<<ceil(k*((n/k) + 1)/(n*1.0))<<"\n";
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