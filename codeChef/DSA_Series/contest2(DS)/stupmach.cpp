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
    int n= 0;
    cin>>n;
    vi v(n);
    ui ans = 0;
    ui min_so_far = UINT64_MAX;
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    for(int i=0; i<n;i++ ){
      // cout<<v[i]<<" ";
      if(v[i]<min_so_far){
        ans += v[i];
        min_so_far = v[i];
      }
      else
        ans+=min_so_far;
    }
    cout<<ans<<"\n";
  }
  return 0;
}