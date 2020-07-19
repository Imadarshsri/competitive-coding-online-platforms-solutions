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
// #define debug(x) cout<< #x << " = " << (x) << "\n"
// #define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl
// #define lookPairs(v) cout<< #v << " : "; for(auto x : v) cout<< x.first << " "<<x.second<<"\n"
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
  
}

int main(){
   /*
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
   */
   fastio

   int cases=1;
   scanf("%d",&cases);
   while(cases--){
      int flag = 0;
      unordered_map<ui,int> m;
      int numbers = 1;
      cin>>numbers;
      ui v[numbers];
      // v.shrink_to_fit();
      // ui sum = 0;
      fo(numbers){
         cin>>v[i];
         if(m[v[i]] >= 1 ){
            cout<<"NO\n";
            flag = 1;
            break;
         }
         m[v[i]]++;
         // if(i!=0)
         //    m[sum]++;
         // debug(sum);
      }
      if(flag == 1) continue;
      for(int i = 0; i < numbers; i++){
         // int k = 1;
         // for(int k = 1; (i + k) < numbers; k++){
         ui sum2 = v[i];
         for(int j = i + 1; j < numbers; j++){
            sum2 |= v[j];
            if(m[sum2] >= 1){
               cout<<"NO\n";
               flag = 1;
               break;
            }
            m[sum2]++;
            // debug(j);
            // debug(sum2);
            
         }
         // }
         if(flag == 1) break;
      }
      if(flag == 1) continue;
      // lookPairs(m);
      m.clear();
      cout<<"YES\n";
   }
   return 0;
}