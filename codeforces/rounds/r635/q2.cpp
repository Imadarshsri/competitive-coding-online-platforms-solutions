#include<bits/stdc++.h>
using namespace std;
//Macros
#define fo(n) for(auto i =0;i<n;i++)
#define fn(x,n) for(;x<n;x++)

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

int main(){
  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    int x=1,n=0,m=0,flag=0;
    cin>>x>>n>>m;
    while(x>=20 && n>0){
      x = (x/2)+10;
      n--;
    }
    x-=(m*10);
    if(x<=0){
      cout<<"YES\n";
    }
    else{
      cout<<"NO\n";
    }
  }
  return 0;
}