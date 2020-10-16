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

// typedef uint64_t ui;
typedef long long ll;
#define N 100001

void simpleSieve(vector<ll> &primes){
  bool v[N];
  memset(v, true, sizeof(v));

  for(ll i = 2; i < N; i++){
    if(v[i] == true){
      for(ll j = (i*i); j < N; j += i){
        v[j] = false;
      }
    }
  }
   for(ll i = 2; i < N; i++){
    if(v[i] == true){
      primes.push_back(i*i);
    }
  }
}


int main(){
  //fastio

  vector<ll> primes;
  simpleSieve(primes);
  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    ll n = 1, k = 1;
    cin >> n >> k;
    int ans1 = (int)(upper_bound(primes.begin(), primes.end(), n) - primes.begin());
    int ans2 = ans1 - (int)(upper_bound(primes.begin(), primes.end(), k) - primes.begin());
    if(ans2 < 0) ans2 = 0;
    cout << ans1 << " " << ans2;
    if(cases) cout <<"\n";
  }
  return 0;
}
