#include<bits/stdc++.h>
using namespace std;


#define endl "\n"
#define pb push_back
#define mp make_pair
#define sz(x) (typeof(x[0]))(x.size())
#define fn(x,n) for(; x < n; x++)
#define all(v) (v).begin(),(v).end()
#define fo(n) for(auto i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef uint64_t ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ui> vui;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef map<int,int> mi;
typedef set<int> si;

const ll mod = 1e9 + 7;
const ll INF = 1e18;

map<ui,ui> jerryStrength;

ui checkAns(ui tomStrength,ui jerry,ui actualJerryStrength){
  if(jerryStrength.find(jerry)!=jerryStrength.end()) return jerryStrength[jerry];
  tomStrength = tomStrength>>1;
  if(tomStrength&1){
    jerryStrength[actualJerryStrength] = jerry>>1;
    return jerry;
  }
  return checkAns(tomStrength,jerry>>1,actualJerryStrength);
}

void solve(){
  ui tomStrength = 1, jStrength=0, ans=0;
  cin>>tomStrength;
  if(tomStrength&1)
    ans = tomStrength>>1;
  else
    ans = checkAns(tomStrength,tomStrength>>1,tomStrength>>1);
  cout<<ans<<"\n";
}

int32_t main(){
  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}