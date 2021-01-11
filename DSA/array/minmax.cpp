#include<iostream>
#include<vector>
#include<limits.h>
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

void minMax(vector<int> &v, int n, vector<int> &ans){
  int min = INT_MIN, max = INT_MAX, i = 0;

  if(n&1){
    min = v[0];
    max = v[0];
    i = 1;
  }
  else{
    min = v[0];
    max = v[1];
    i = 2; 
  }
  for(; i < n; i+=2){
    if(v[i] < v[i+1]){
      if(min > v[i])
        min = v[i];
      if(max < v[i+1])
        max = v[i+1];
    }
    else{
      if(min > v[i+1])
        min = v[i+1];
      if(max < v[i])
        max = v[i];
    }
  }
  ans[0] = min;
  ans[1] = max;
}
void solve(){
  vector<int> v, ans(2,0);
  int n;
  cin>>n;
  for(int i = 0; i <  n; i++){
    cin>>v[i];
  }
  minMax(v,n, ans);
  cout<<"Min: "<<ans[0] << "Max: "<<ans[1]<<endl;
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