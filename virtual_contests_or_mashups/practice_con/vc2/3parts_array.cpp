#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define readSeq(v, n) for(int i = 0; i < n; i++) cin>>v[i]
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define debug(x) cout<< #x << " " << x << endl
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;

int bs(const vector<ui>& v, ui x){
  int l = 0, r = v.size() - 1;
  while(l <= r){
    int mid = l + (r - l)/2;
    if(v[mid] == x) return mid;
    else if(v[mid] < x) r = mid - 1;
    else l = mid + 1;
  }
  return -1;
}

void solve(){
  ui n = 1, ans = 0;
  cin >> n;
  vector<ui> pre(n, 0), a(n, 0), suf(n,0);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(i != 0)
      pre[i] = pre[i - 1] + a[i];
    
    else{
      pre[i] = a[i];
    }
  }

  suf[n - 1] = a[n - 1];
  for(int i = n - 2; i >= 0; i--){
    suf[i] = suf[i+1] + a[i];
  }

  // look(a);
  // look(pre);
  // look(suf);

  vector<ui>::iterator it = suf.begin(), it2 = pre.begin();
  for(auto x = pre.begin(); x != pre.end(); x++){
    auto p = bs(suf, *x);//find(suf.begin(), suf.end(), *x);
    if(p != -1 && p > (x - it2)){
      // debug(*x);
      ans = max(ans, *x);
    }
  }

  cout<<ans;
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