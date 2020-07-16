#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    n/=2;
    if(n&1){
      cout<<"NO\n";
      continue;
    }
    else{
      cout<<"YES\n";
      for(int i=1;i<=n;i++){
        cout<<i*2<<" ";
      }
      // uint64_t sum = 0;
      int i=1;
      for(i=1;i<n;i++){
        cout<<i*2 - 1<<" ";
        // sum+=(i*2 - 1);
      }
      cout<<(i*3 - 1)<<"\n";
    }
  }
}