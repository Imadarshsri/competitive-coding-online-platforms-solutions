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
///TODO: Disclaimer :: This is INTERACTIVE PROBLEM !! Use flush after every output
void solve(){
  int prob, noOfPop = 60, queryResult = -1;
  cin>>noOfPop>>prob;
  int r1 = 0, r2 = 0, c1 = 0, c2 = 0;
  int numOfQueries = 18000;
  int i=0,j=0;
  int arr[noOfPop][noOfPop];
  fn(i,noOfPop){
    fn(j,noOfPop){
      cout<<1<<" "<<(i+1)<<" "<<(j+1)<<" "<<(i+1)<<" "<<(j+1);
      fflush(stdout);
      cin>>queryResult;
      if(queryResult!=-1){
        if(queryResult==1)
          arr[i][j] = 1;
        else
          arr[i][j] = 0;
      }
      else
        break;
    }
  }
  if(i==noOfPop){
    i=0;j=0;
    cout<<2;
    fn(i,noOfPop){
      fn(j,noOfPop)
      cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
  }
}
int main(){
  fastio

  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}