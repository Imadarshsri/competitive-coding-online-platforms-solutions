#include<bits/stdc++.h>
using namespace std;
//Macros
#define fo(n) for(auto i =0;i<n;i++)
#define fn(x,n) for(auto i=x;i<n;i++)

#define see(x) cout<<#x<<" = "<<(x)<<"\n"
#define look(v) cout<<#v<<" : "; for(auto x:v) cout<<x<<" "; cout<<endl

#define vi vector<int> 
#define vui vector<uint64_t> 
#define vvi vector<vector<int>>
#define mi map<int>

#define pb push_back
#define mp make_pair
#define ll long long
#define ui uint64_t
#define rem 1000000007
#define MAX 100000000

ui check(ui n){
  ui x=5,y=0;
  while(n/x>=1){
    y+= n/x;
    x*=5;
  }
  return y;
}
int main(){
  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    ui n=1;
    cin>>n;
    cout<<check(n)<<"\n";
  }
  return 0;
}