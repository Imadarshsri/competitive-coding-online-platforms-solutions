#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef uint64_t ui;

void solve(){
  int n = 1;
  cin>>n;
  // debug(n);
  vector<int> a(n), b(n);
  map<int,int> countA, countB;
  for(int i = 0; i < n; i++){
    cin>>a[i];
    countA[a[i]]++;
  }
  for(int i =0; i< n; i++){
    cin>>b[i];
    countB[b[i]]++;
  }
  if(countA == countB){
    cout<<"0\n";
    return;
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