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
#define sz(x) int(x.size()),
#define fn(x,n) for(; x < n; x++)
#define all(v) (v).begin(),(v).end()
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl
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

int main(){
  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    string str;
    cin>>str;
    vector<ui> v(str.length());
    int i=2;
    if(str.length()>=2){
      v[0] = 0;
      if(str[1]!=str[0]) v[1]=1;
    }
    fn(i,str.length()){
      v[i] += (str[i-1]!=str[i] && (v[i-1]==v[i-2])) ? v[i-1]+1:v[i-1];
      // debug(v[i]);
    }
    // debug(v[str.length()-1]);
    cout<<v[str.length()-1]<<"\n";
  }
  return 0;
}