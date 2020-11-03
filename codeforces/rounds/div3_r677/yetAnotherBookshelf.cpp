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
  int n, ans = 0;
  cin>>n;
  vector<int> v(n);
  for(int i = 0; i < n ; i++) cin >> v[i];
  for(int i = 0; i < n ; i++){
    if(v[i] == 1){
      int cnt = 0;
      i++;
      while(i < n && v[i] == 0){
        cnt++;
        i++;
      }
      if(i < n){
        ans += cnt;
        i--;
      }
    }
  }
  cout<<ans<<"\n";
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