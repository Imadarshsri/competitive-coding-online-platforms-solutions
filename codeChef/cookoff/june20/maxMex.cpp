#include <bits/stdc++.h>
using namespace std;

int main(){
  int cases = 1;
  scanf("%d",&cases);
  while(cases--){
    int n=1,m=1;
    cin>>n>>m;
    set<int> s;
    int ans =0;
    for(int i = 0;i<n;i++){
      int x;
      cin>>x;
      if(x!=m){
         s.insert(x);
        ans++;
      }
    }
    int mex = 1;
    while(s.count(mex)) mex++;
    if(mex!=m) ans = -1;
    cout<<ans<<"\n";
  }
}