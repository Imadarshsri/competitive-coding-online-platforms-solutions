// --------------------<optimizations>--------------------\
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)\
#pragma GCC optimize("unroll-loops")
// -------------------</optimizations>--------------------

#include<bits/stdc++.h>
using namespace std;
//Macros
#define endl "\n"
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define fn(x,n) for(; x < n; x++)
#define all(v) (v).begin(),(v).end()
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl
#define lookPairs(v) cout<< #v << " : "; for(auto x : v) cout<< x.first << " "<<x.second<<"\n"
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

void solve(){
  int x,y,z;
  uint64_t a = 0, b = 0, c = 0;
  cin>>x>>y>>z;
  if(x==y && x==z){
     a = x;
     b = x;
     c = x;
   //   cout<<"YES\n"<<x<<" "<<x<<" "<<x<<"\n";
  }
  else if(x==y){
     a = max(x,y);
     b = z;
     c = min(y,z);
   //   cout<<"YES\n"<<x<<" "<<z<<" "<<z-1<<"\n";
  }
  else if(x==z){
     a = y;
     b = z;
     c = min(y,z);
   //   cout<<"YES\n"<<y<<" "<<z<<" "<<y-1<<"\n";
  }
  else if(y==z){
     a = x;
     c = y;
     b = min(x,z);
   //   cout<<"YES\n"<<x<<" "<<x - 1<<" "<<y<<"\n";
  }
  if((x == max(a,b)) && (y == max(a,c)) && (z == max(b, c))){
     cout<<"YES\n"<<a<<" "<<b<<" "<<c<<"\n";

  }
  else{
     cout<<"NO\n";
  }
}

int main(){
/*
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
*/
  //fastio

  int cases=1;
  //fastscan(cases);
  scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}