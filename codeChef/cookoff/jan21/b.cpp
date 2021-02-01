#include<iostream>
using namespace std;

void solve(){
  int a, b;
  cin >> a >> b;
  cout<<b - a + 1  + b - a << "\n";
}

int main(){
  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}