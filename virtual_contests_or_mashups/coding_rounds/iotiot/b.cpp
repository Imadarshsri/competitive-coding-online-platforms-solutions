#include<bits/stdc++.h>
#include<cctype>

using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define readSeq(v, n) for(int i = 0; i < n; i++) cin>>v[i];
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

void solve(){
  int flag = 0;
  vector<vector<string>>v(5);
  
  vector<vector<int>>m(5);
  for(int i = 0; i < 5; i++){
    v[i] = vector<string>(4);
    m[i] = vector<int>(4);
    for(int j = 0; j < 4; j++){
      cin>>v[i][j];
      
      int x = 0;
      for(auto c:v[i][j]){
        if(isdigit(c)){
          x = x*10 + (c - '0');
        }
      }
      if(x >= 150) flag = -1;
      else if(x == 0 || x == 1){
          m[i][j] = x;
      }
      else {
        m[i][j] = x/2;
      }
  
      x = 0;
    }
  }
  
  if(flag == -1){
    cout<<"array value out of range\n";
    return;
  }
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 4; j++){
      int w = 4*i + j;
      if(w == 0) cout<<"[["<<m[i][j]<<", ";
      else if(w == 19) cout<<m[i][j]<<"]]\n";
      else if(w%4 == 1 || w%4 == 2) cout<<m[i][j]<<", ";
      else if( w == 4  || w == 8 || w == 12 || w == 16){
        cout<<"["<<m[i][j]<<", ";
      }
      else if( w == 3|| w == 7 || w == 11 || w == 15) {
        cout<<m[i][j]<<"], ";
      }
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