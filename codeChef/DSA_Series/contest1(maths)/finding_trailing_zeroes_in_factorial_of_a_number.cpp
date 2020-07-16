#include<bits/stdc++.h>
using namespace std;
#define ui uint64_t

ui check(ui n){
  ui x=5,y=0;
  while(n/x>=1){
    y+= n/x;
    x*=5;
  }
  return y;
}
int main(){
  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    ui n=1;
    cin>>n;
    cout<<check(n)<<"\n";
  }
  return 0;
}