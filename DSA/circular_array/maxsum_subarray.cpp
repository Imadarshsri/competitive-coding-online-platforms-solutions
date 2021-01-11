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

void solve(){
  long long int n = 1;//, maxCircularSum = 0;
  cin>>n;
  vector<long long int> v(n);
  for(long long int i = 0; i < n; i++){
    cin>>v[i];
  }
  ///Kadane's Algorithm Circular array concepts
  long long int localSum = 0, finalAns = INT_MIN, maxKSum = INT_MIN;
  for(long long int j = 0; j < n; j++){
    localSum = v[j], maxKSum = v[j];
    for(long long int i = j; i < n+j; i++){
      localSum = localSum + v[i%n];
      if(localSum > maxKSum){
        maxKSum = localSum;
      }
      if(localSum < 0) localSum = v[j];
    }
    finalAns = max(maxKSum, finalAns);
  }
  cout<<finalAns<<"\n";
  return;  
}

int main(){
  //fastio

  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}