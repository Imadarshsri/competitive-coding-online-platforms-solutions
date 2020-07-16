#include <bits/stdc++.h>
using namespace std;

int main(){
  uint64_t testcases,max = 0;
  cin>>testcases;
  while(testcases-->0){
    int n,cnt=1;
    cin>>n;
    if(n==1){
      int x;
      cin>>x;
      cout<<cnt<<"\n";
      continue;
    }
    vector<int>v;
    for(int i=0;i<n;i++){
      int x= 0;
      cin>>x;
      v.push_back(x);
      // cout<<v[i]<<" ";
    }
    for(int i=1;i<n;i++){
      if(v[i]<v[i-1]) cnt++;
    }
    cout<<cnt<<"\n";
    v.clear();
  }
  return 0;
}