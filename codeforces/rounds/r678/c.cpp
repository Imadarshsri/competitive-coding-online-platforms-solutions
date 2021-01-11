#include<bits/stdc++.h>

using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define readSeq(v, n) for(int i = 0; i < n; i++) cin>>v[i];
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl
#define N 1000000007
typedef uint64_t ui;

ui fac(ui n){
  if(n == 1) return 1;
  ui ans = 1;
  for(ui i = 2; i <= n; i++)
    ans = ((ans%N) * (i %N))%N;
  
  return ans;
}

uint64_t solve(){
  ui n, x, pos = 0, ans = 1;
  cin >> n >> x >> pos;
  int l = 0, r = n, m = 0;
  int big = max((ui)0, (n - x));
  int less = max((ui)0, (n - 1 - big));
  while(l < r){
    m = l + (r - l)/2;
    if(m == pos){
      l = m + 1;
    }
    else if(m < pos){
      ans = ((ans%N)*(less%N))%N;
      less--;
      l = m + 1;
    }
    else{
      ans = ((ans%N)*(big%N))%N;
      big--;
      r = m;

    }
    n--;
  }
  ans = ((ans%N)*(fac(n)%N))%N;
  return ans;
}

int main(){
  //fastio

  int cases=1;
  //fastscan(cases);
  // scanf("%d",&cases);
  while(cases--){
    cout<<solve()<<"\n";
  }
  return 0;
}