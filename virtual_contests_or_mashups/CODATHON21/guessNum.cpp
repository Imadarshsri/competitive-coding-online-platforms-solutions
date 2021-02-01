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
typedef long long int ll;
#define N 1e10

void solve(){
  int n;
  char c;
  cin>>n;
  ll l = (-N), r = N, x = 0;
  fo(n){
    cin>>c>>x;
    if((c == 'R') && (x > l)) l = x;
    else if(c == 'L' && (x < r)) r = x;
  }
  if((l == -N) || (r == N) || ((r-l) <= 1))
    cout<<"-1\n";
  else
    cout<<r-l-1<<"\n"; 
}

int main(){
  // fastio
  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}