#include<bits/stdc++.h>
using namespace std;
//Macros
#define fo(n) for(auto i =0;i<n;i++)
#define fn(x,n) for(;x<n;x++)

// #define see(x) cout<<#x<<" = "<<(x)<<"\n"
// // // #define look(v) cout<<#v<<" : "; for(auto x:v) cout<<x<<" "; cout<<endl

#define pii pair<int,int> 
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
    int n,sym;
    pii max_dep = mp(0,0),max_ele = mp(0,0);
    int depth_check=0,symbols_check=0,idx=0, ans = 0;
    cin>>n;
    fo(n){
      cin>>sym;
      if(sym==1){
        if(symbols_check==0){ 
          idx = i+1;
          ans = 0;
        }
        depth_check++;
        if(max_dep.first<depth_check){
          max_dep.first = depth_check;
          max_dep.second = i+1;
        }
        symbols_check++;
      }
      else{
        // cout<<"\n\nHey I am decrementing it:: \n";
        if(symbols_check>0){
          ans += 2;
        }
        symbols_check--;
        depth_check--;
      }
      // cout<<"\ncheck ("<<i<<")\nans = "<<ans;
      if(symbols_check==0 && max_ele.first<ans){
        // cout<<"\nHey Im in\n";
        max_ele.first = ans;
        max_ele.second = idx;
      }
    //  cout<<"\nMax Depth == "<<max_dep.first<<"\nMax depth Postion = "<<max_dep.second<<"\nMaxing symbols = "<<max_ele.first<<"\nMax Symbols position = "<<max_ele.second<<"\n";
    }
    cout<<max_dep.first<<" "<<max_dep.second<<" "<<max_ele.first<<" "<<max_ele.second<<"\n";

  return 0;
}