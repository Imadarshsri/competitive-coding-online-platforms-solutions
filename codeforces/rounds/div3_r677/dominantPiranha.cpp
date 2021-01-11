#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define readSeq(v, n) for(int i = 0; i < n; i++) cin>>v[i];
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;

void solve(){
  int n, ans = 0, mx = 0, idx = -1;
  cin>>n;
  vector<int> v(n);
  for(int i = 0; i < n ; i++) {
    cin >> v[i];
  }
  priority_queue<pair<int, int> > pq; 
  for(int i = 0; i< n ; i++ ){
    pq.push(make_pair(v[i], i));
  }
  while (pq.empty() == false){ 
    pair<int, int> top = pq.top(); 
    // cout << pq.top() << " "; 
    int i = top.second;
    if(i < n && (v[i] >= mx) && ((i > 0 && v[i] > v[i-1]) || (i < (n - 1) && v[i] > v[i+1]))){
      mx = v[i];
      idx = i;
    }
    pq.pop(); 
  }  
  idx == -1 ? cout<<"-1\n" : cout<<idx + 1<<"\n";
}

int main(){
  //fastio

  int cases=1;
  //fastscan(cases);
  scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}