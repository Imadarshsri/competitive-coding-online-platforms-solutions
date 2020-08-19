#include<iostream>
#include <math.h>

using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;
typedef uint64_t ui;

void solve(){
  int pc, pr;
  cin>>pc>>pr;
  int chefDigits = ceil(pc/9.0);
  int rickDigits = ceil(pr/9.0);
  if(chefDigits < rickDigits) cout<<"0 "<<chefDigits<<"\n";
  else if(chefDigits >= rickDigits) cout<<"1 "<<rickDigits<<"\n";
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