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

  char cmp[3];
void check (int l, int r){
  cout<<"Entry\n";
  debug(l);debug(r);
  if(l>r||strcmp(cmp,"E")==0) return;
  int mid = l+ (r-l)/2;
  printf("%d\n",mid);
  fflush(stdout);
  scanf("%s",cmp);
  if(strcmp(cmp,"L")==0){
    // r = mid-1;
    cout<<"== L is given ==\n";
  
    check(mid+1,r);
    cout<<"r-1\n";    
    debug(l);debug(r);
    if(l==r||strcmp(cmp,"E")==0) return;
    check(l,mid-1);
    cout<<"r-1\n";
    debug(l);debug(r);
    if(l==r||strcmp(cmp,"E")==0) return;
  }
  else if(strcmp(cmp,"G")==0){
    // l = mid+1;
  cout<<"== R is given ==\n";

    check(l,mid-1);
    cout<<"l-1\n";
    debug(l);debug(r);
    if(l==r||strcmp(cmp,"E")==0) return;
    check(mid+1,r);
    cout<<"l-2\n";
    debug(l);debug(r);
    if(l==r||strcmp(cmp,"E")==0) return;
  }
  return;
}
void solve(){
  int l=1,r=1;
  scanf("%d",&r);
  int i=0;
  check(l,r);
  // while(strcmp(cmp,"E") != 0){

    // int mid = (r+l)/2;
    // printf("%d\n",mid);
    // fflush(stdout);
    // scanf("%s",cmp);
    // if(strcmp(cmp,"L")==0){
    //   r = mid-1;
    // }
    // else if(strcmp(cmp,"G")==0){
    //   l = mid+1;
    // }
    // else{

    //   break;
    // }
    // i++;
  // }
  return;
}

int main(){
  // fastio
  int cases=1;
  // scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}