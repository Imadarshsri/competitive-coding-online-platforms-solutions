#include<iostream>
#include<vector>

using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define readSeq(v, n) for(int i = 0; i < n; i++) cin>>v[i];
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl
#define MOD 1000000007
typedef uint64_t ui;

void dfs(int i, int j, int n, int m, vector <string> &s, uint64_t pathCount, uint64_t downCnt, uint64_t rightCnt, uint64_t &ans){
  if(i == (n-1) && j ==  (m-1)){
    if(pathCount == 0) pathCount = 1;
    
    cout<<" pathCount: "<< pathCount<<" down: "<< downCnt<<" rght: "<< rightCnt<<" ans->"<<ans<<"\n";
    if(rightCnt > 0){
      pathCount = max((max(pathCount,(uint64_t)1))%MOD * (rightCnt)%MOD, (uint64_t)1)%MOD;
      cout<<"mul r\n";
    }
    if(downCnt > 0){
      pathCount = max((max(pathCount,(uint64_t)1))%MOD * (downCnt)%MOD, (uint64_t)1)%MOD;
      cout<<"mul d\n";
    }
    ans = ((ans%MOD) + (max(pathCount,(uint64_t)1) % MOD))% MOD;
    cout<<" pathCount: "<< pathCount<<" down: "<< downCnt<<" rght: "<< rightCnt<<" ans->"<<ans<<"\n";
    // cout<<endl;
    return;
  }
  cout<<"Path: "<<" i->"<<i<<" j->"<<j<<" pathCount: "<< pathCount<<" down: "<< downCnt<<" rght: "<< rightCnt<<" ans->"<<ans<<"\n";
  if((i < (n - 1) ) && s[i + 1][j] == '.'){
    s[i][j] = '#';

    // if (s[i+1][j] == '.'){
      if(pathCount == 0) pathCount = 1;
      if(rightCnt > 0)
        pathCount = max((max(pathCount,(uint64_t)1))%MOD * (rightCnt)%MOD, (uint64_t)1)%MOD;
      
      cout<<"DDFS pathCount: "<< pathCount<<" down: "<< downCnt<<" rght: "<< rightCnt<<" ans->"<<ans<<"\n";
      dfs(i+1, j, n, m, s, pathCount, (downCnt + 1)%MOD, 0, ans);
    // }
    s[i][j] = '.';
  }
  if((j < (m - 1) ) && s[i][j + 1] == '.'){
    s[i][j] = '#';
    // if (s[i][j+1] == '.'){
      if(pathCount == 0) pathCount = 1;
      if(downCnt > 0)
        pathCount = max((max(pathCount,(uint64_t)1))%MOD * (downCnt)%MOD, (uint64_t)1)%MOD;
      cout<<"RDFS pathCount: "<< pathCount<<" down: "<< downCnt<<" rght: "<< rightCnt<<" ans->"<<ans<<"\n";
      dfs(i, j + 1, n, m, s, pathCount, 0, (rightCnt + 1)%MOD, ans);
    // }
    s[i][j] = '.';
  }
  
  cout<<"Backing on Path: "<<" i->"<<i<<" j->"<<j<<" pathCount: "<< pathCount<<" down: "<< downCnt<<" rght: "<< rightCnt<<" ans->"<<ans<<"\n";
  s[i][j] = '#';

}
void solve(){
  int n  = 0, m = 0;
  cin >> n >> m;
  uint64_t ans = 0, pathCount = 1; 
  vector<string> s(n);
  for(int i = 0; i < n; i++){
    cin >> s[i];
  }
  //preform dfs to knoe the no. of paths 
  dfs(0,0,n, m, s,pathCount,0,0, ans);

  // for(auto x: pathCount){
  //   ans += (x - 1)%MOD;
  // }
  cout<<ans<<endl;
  
  for(int i = 0; i < n; i++){
    cout << s[i]<<endl;
  }
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