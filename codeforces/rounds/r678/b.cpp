#include<iostream>
#include<vector>

using namespace std;

void solve(){
  int n = 1, m = 0, ans = 0;
  cin >> n;
  if(n&1){ //odd
    int x = (n - 1)/2;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(((i == x) || (i == (x - 1)) || (i == (x + 1))) && ((j == x) || (j == (x - 1)) || (j == (x + 1))))
          cout<<"1 ";
        else if(i == j || i == (n - j - 1))
          cout<<"1 ";
        else 
          cout<<"0 ";
      }
      cout<<"\n";
    }
  }
  else{
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(i == j || i == (n - j - 1))
          cout<<"1 ";
        else 
          cout<<"0 ";
      }
      cout<<"\n";
    }
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