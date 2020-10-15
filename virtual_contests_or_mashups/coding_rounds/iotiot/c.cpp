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
  
int fc (int n) { 
    int res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 
int ncr(int n, int r) {
    return fc(n) / (fc(r) * fc(n - r)); 
} 
  
void solve(){
  int n , m, o;
  cin>>m>>o>>n;
  int ob = o/2;
  int mb = n - ob;
  cout<<(ncr(ob-1, o))*ncr(mb -1, m)<<"\n";
}

int main(){
  int cases=1;
  while(cases--){
    solve();
  }
  return 0;
}