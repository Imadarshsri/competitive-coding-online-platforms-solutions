#include<iostream>
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
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<max(a+b,c+d)<<"\n";
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