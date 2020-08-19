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
   int a, b, c;
   cin>>a>>b>>c;
   //a-> Retail price at 1st shop Rs. a per pc. || Bulk price at 2d shop -> Rs. c per b items
   if((ui) a*b <= (ui) c){
      if(a < c){      
         cout<<1<<" -1\n";
         return;
      }
      else if(a >= c){
         cout<<-1<<" -1\n";
         return;
      }
      // else{
      //    cout<<"-1 "<<b<<"\n";
      //    return;
      // }
   }
   else if((ui)a*b > (ui) c){
   //    cout<<"-1 "<<b<<"\n";
      if(a < c){      
         cout<<1<<" "<<b<<"\n";
         return;
      }
      else if(a >= c){
         cout<<"-1 "<<b<<"\n";
         return;
      }
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