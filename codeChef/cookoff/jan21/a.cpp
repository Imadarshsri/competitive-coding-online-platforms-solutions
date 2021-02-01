#include<iostream>
#include<string>
#include<algorithm>

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
  string s;
  cin >> s;
  bool con1 = false, con2 = false, con3 = false, con4 = false;
  int len = s.length();
  if(len <10){
    cout<<"NO\n";
    return;
  }
  for(int i = 0; i < len; i++){
    char c = s[i];
    if(!con1 && (c >= 'a' && c <= 'z')){
      con1 = true;
    }
    else if(!con2 && (c >= 'A' && c <= 'Z') && (i > 0 && i < (len-1))){
      con2 = true;
    }
    else if(!con3 && (c >= '0' && c <= '9') && (i > 0 && i < (len-1))){
      con3 = true;
    }
    else if(!con4 && ((c == '@') || (c == '#') || (c == '%') || (c == '&') || (c == '?'))  && (i > 0 && i < (len-1)))
      con4 = true;
  }
  if(con1 && con2 && con3 && con4) cout<<"YES\n";
  else cout<<"NO\n";
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