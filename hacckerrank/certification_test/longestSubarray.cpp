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
  #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
  
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
  
 int solve(vi arr){
    int ans = 0,  n = arr.size();
    set<int> s;
    for(int i =0; i < n; i++){
      int count = 1, prev = arr[i];
      int j = i + 1;
      s.insert(prev);
      for(;j<n;j++){
        if((((arr[j] - prev) == -1) || ((arr[j] - prev) == 0) || ((arr[j] - prev) == 1))){
          s.insert(arr[j]);
          if(s.size() > 2) break;
          count++;
          prev = arr[j];
          s.insert(prev);
        }
        else{
          break;
        }
      }
      ans = max(ans, count);
      if(j==n) break;
      s.clear();
    }

    return ans;
  }
  
  int main(){
  /*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
  */
    fastio;
  
    int cases=1;
    //fastscan(cases);
    // scanf("%d",&cases);
    while(cases--){
        
      int n=1;
      cin>>n;
      vector<int> v(n);
      fo(n) cin>>v[i];
      cout<<solve(v)<<"\n";
    }
    return 0;
  }