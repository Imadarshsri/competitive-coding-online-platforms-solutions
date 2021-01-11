#include<iostream>
#include<vector>

using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define readSeq(v, n) for(int i = 0; i < n; i++) cin>>v[i];
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;
typedef long long ll;


void solve(){
  ll n, k;
  cin >> n >> k;
  ll l = -1, r = n + 1;

  while(l < r){
    ll m = l + (r - l)/2;
    if((n - m) * (n - m + 1)/2 - m > k){
      l = m;
    }
    else 
      r = m;
  }
  cout << r << "\n";
}

int main(){
  //fastio

  int cases=1;
  //fastscan(cases);
  // scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}