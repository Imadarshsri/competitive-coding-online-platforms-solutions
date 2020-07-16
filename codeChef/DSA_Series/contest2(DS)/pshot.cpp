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
    int n,aScore=0,bScore=0;
    cin>>n;
    int aleft = n,bleft = n;
    string shots;
    cin>>shots;
    int i=0;
    for(i=0;i<2*n ;i++){
      // cout<<"Aleft  = "<<aleft<<" Bleft = "<<bleft<<"\n";
      if(i&1){
        bleft--;
        
        bScore += stoi(shots.substr(i,1));
      }
      else{
        aleft--;
        aScore += stoi(shots.substr(i,1));
      }
      if((aScore > bScore +bleft)|| (bScore > aScore+ aleft)) {
        cout<<(i+1);
        break;
      }
      // cout<<"Shots are ::"<<shots[i]<<" AScore = "<<aScore<<" Bscore = "<<bScore<<"\n"; 
    }
    if(i==2*n)cout<<2*n;
    cout<<"\n";
  }
  return 0;
}