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
#define look(v)  for(auto x : v) cout<< x << " "
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
   unordered_map<int,int> m;
   fo(50){
      m[i+1] = 2;
   }
  int n;
  cin>>n;
  vi v(2*n), ans, ans2;
  fo(2*n){
     cin>>v[i];
  }
   // ans[0] = v[0];
   // ans[n - 1] = v[(2*n) - 1];
   // n-=2;
   int temp = n, temp2 = n, temp3 = n;
   int i =0 , j =0;
   if(n>0){
      // for(int i = 0; i <  (2*temp) && n > 0; i++){
      //     if(m[v[i+1]] == 2){
      //        ans2.pb(v[i]);
      //       // ans[n - temp2] = v[i];//(i+1)/2
      //       m[v[i+1]]--;
      //       n--;
      //       temp2++;
      //     }
      // }
       for(i = 0, j = (2*temp) - 1; i < j && n > 0; i++, j--){
          if(m[v[i]] == 2){
            ans.pb(v[i]);//(i+1)/2
            m[v[i]]--;
            n--;
            temp2++;
          }
          if(m[v[j]] == 2){
            ans2.insert(ans2.begin(),v[j]);
            m[v[j]]--;
            n--;
          }
       }
       if(i == j && n&1) {
          if(m[v[i]] == 2){
            ans.pb(v[i]);
            m[v[i]]--;
            n--;
          }
       }
   }
   look(ans);
   look(ans2);
   cout<<"\n";
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