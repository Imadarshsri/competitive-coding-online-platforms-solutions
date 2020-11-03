#include<bits/stdc++.h>
using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;
typedef uint64_t ui;

//Problem Statement
/**/
void solve(){
  int n = 1;
  cin>>n;
  set<int> s;
  while(n--){
     int x = 0;
     cin>>x;
     s.insert(x);
  }
  int k = 1;
  cin>>k;
  auto itr = s.begin();
  advance(itr, k - 1);
   cout<<*itr<<"\n";
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