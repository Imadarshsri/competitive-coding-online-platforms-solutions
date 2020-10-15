#include<iostream>
#include<vector>

using namespace std;
// //Macros
// #define endl "\n"
// #define fn(x,n) for(; x < n; x++)
// #define fo(n) for(auto i = 0; i < n; i++)
// #define debug(x) cout<< #x << " = " << (x) << "\n"
// #define readSeq(v, n) for(int i = 0; i < n; i++) cin>>v[i];
// #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
// #define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

// typedef uint64_t ui;

void solve(){
  int n , q;
  cin>>n>>q;
  vector<vector<int>> v(n);
  for(int i = 0; i < n; i++){
    int a =0;
    cin>>a;
    v[i] = vector<int>(a);
    for(int j = 0; j < a; j++){
      cin>>v[i][j];
    }
  }
  while(q--){
    int i =0, j =0;
    cin>>i>>j;
    cout<<v[i][j]<<"\n";
  }
}

int main(){
  int cases=1;
  // scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}