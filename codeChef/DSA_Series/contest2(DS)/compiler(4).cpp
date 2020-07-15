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
    string str;
    cin>>str;
    int ans = 0, seq_cnt=0;
    stack<char> stk;
    for(int i=0;i<str.length();i++){
      if(str.substr(i,1)=="<" ) seq_cnt++;
      else seq_cnt--;

      if( seq_cnt==0) ans = i+1 ;
      else if ( seq_cnt<0)  break;
    }
    cout<<ans<<"\n";
  }
  return 0;
}