#include<iostream>
#include<vector>

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
  int n= 0, x = 0;
  cin>>n>>x;
  vector<int> a(n),b(n);
  for(int i  =0 ;i < n; i++) cin>>a[i];
  for(int i  =0 ;i < n; i++) cin>>b[i];

  for(int i = 0, j = n - 1; i < n && j >= 0; i++, j--){
     if(a[i] + b[j] > x) {
        cout<<"No\n";
        return;
     }
  }   
  cout<<"Yes\n";
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