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
#define see(x) cout<< #x << " = " << (x) << "\n"
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
 
string solve(){
  mi changes;

    int n;
    ui chef=0;
    cin>>n;
    vi v(n);
    fo(n){
      cin>>v[i];
    }
    for(int i=0;i<n;i++){
      v[i]-=5;
      if((v[i] == 5) && changes[v[i]]>0){
        ///Give him exact change  for 10  i.e 5
        // for 15 i.e. 10
          changes[v[i]]--; 
          changes[v[i]+5]++;        
      }
      else if(v[i] == 10 && changes[v[i]]>0 ||changes[v[i]-5]>1){
        if(changes[v[i]]>0){
          changes[v[i]]--; 
          changes[v[i]+5]++;        
        }
        else if(changes[v[i]-5]>1){
          changes[v[i]-5]-=2;
          changes[v[i]+5]++;        
        }
      }
      else if(v[i]==0){
          changes[5]++;        
      }
      else{
        return "NO";
      }
    }
    return "YES";
}

int main(){
  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    cout<<solve()<<"\n";
  }
  return 0;
}