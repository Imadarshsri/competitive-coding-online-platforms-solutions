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
    int n=1, a=1, b=1, c=1;
    cin>>n;
    ui max= 0;
    while(n--){
      cin>>a>>b>>c;
      ui x = (b/(a+1))*c;
      max= max>x ? max : x;
    }
    cout<<max<<"\n";
  }
  return 0;
}