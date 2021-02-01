#include<iostream>
#include<vector>
#include<string>

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

void solve(){
  int n;
  cin>>n;
  string s, a = "";
  cin>>s;
  int x = 0;
  fo(n){
    if(i == 0) {
      a += '1';
      x = 1 + (s[i] - '0');
      continue;
    }
    if((x == 2) && (s[i] - '0') == 1){
      a += '0';
      x = 1;
    }
    else if(((x == 1) || (x == 0)) && (s[i] - '0') == 1){
      a += '1';
      x = 2;
    }
    else if(((x == 2) || (x == 0)) && (s[i] - '0') == 0){
      a += '1';
      x = 1;
    }
    else if(((x == 1)) && (s[i] - '0') == 0){
      a += '0';
      x = 0;
    }
  }
  cout<<a<<"\n";
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