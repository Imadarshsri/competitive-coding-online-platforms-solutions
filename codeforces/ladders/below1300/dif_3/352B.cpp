// #include<iostream>
// #include<vector>
// #include<set>
// #include<algorithm>
// #include<fstream>
#include<bits/stdc++.h>
using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;
typedef uint64_t ui;

void solve(){
   int n = 1;
   cin>>n;
   vector<int> v(n);
   set<int> s;
   vector<pair<int,int>> ans;
   map <int,int> previousX, cmDiff, tempDiff;
   fo(n){
      cin>>v[i];
      s.insert(v[i]);
      previousX[v[i]] = -1;
      cmDiff[v[i]] = 0;
      tempDiff[v[i]] = -1;
   }

   for(int i = 0; i < n ;i++){
      if(cmDiff[v[i]] == -3){
         continue;
      }
      if(previousX[v[i]] == -1){
         previousX[v[i]] = i;
      }
      else if(tempDiff[v[i]] == -1){
         tempDiff[v[i]] = i - previousX[v[i]];
         previousX[v[i]] = i;
         cmDiff[v[i]] = tempDiff[v[i]];
      }
      else{
         tempDiff[v[i]] = i - previousX[v[i]];
         previousX[v[i]] = i;
      }

      if(tempDiff[v[i]] != -1 && cmDiff[v[i]] != tempDiff[v[i]]){
         // cout<<"breaking\n";
         cmDiff[v[i]] = -3;
      }
   }
   int cnt = 0;
   for(auto x : cmDiff){
      if(x.second != -3){
         cnt++;
      }
   }
   cout<<cnt<<"\n";
   if(cnt>0){
      for(auto x : cmDiff){
         if(x.second != -3){
            cout<<x.first<<" "<<x.second<<"\n";
         }
      }
   }
}

int main(){
  fastio

//   freopen("input.txt","w",stdin);
//   freopen("output.txt","w",stdout);
//   cout<<"100000\n";
//   for(int i = 1; i < 100000; i++) cout<<i<<" ";
  int cases=1;
  //fastscan(cases);
//   scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}