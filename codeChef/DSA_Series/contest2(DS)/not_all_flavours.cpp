#include<bits/stdc++.h>
using namespace std;
//Macros
#define fo(n) for(auto i =0;i<n;i++)
#define fn(x,n) for(;x<n;x++)

#define see(x) cout<<#x<<" = "<<(x)<<"\n"
///Displaying set and vector
#define look(v) cout<<#v<<" : "; for(auto x:v) cout<<x<<" "; cout<<endl
///Displaying map and vector<pair<int,int>>
#define seeMap(m) cout<<#m<<" : ";for(auto x: m) cout<<"["<<x.first<<", "<<x.second<<"] ";cout<<end;
#define pii pair<int,int> 
#define vi vector<int> 
#define vui vector<uint64_t> 
#define vvi vector<vector<int>>
#define mi map<int,int>
#define pb push_back
#define mp make_pair
#define ll long long
#define ui uint64_t

#define rem 1000000007
int main(){
  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    int noOfCakes=1,noOfFlavours = 2;
    ui ans=0,localAns=0; 
    cin >> noOfCakes >> noOfFlavours;
    vi cakes(noOfCakes), maxCount(noOfCakes);
    maxCount[0] = 1;
    for(int i=0;i<noOfCakes;i++){
      cin>>cakes[i];
      if(i!=0){
        if(cakes[i-1]==cakes[i]){
          maxCount[i] = maxCount[i-1]+1;
        }
        else{
          maxCount[i] = 1;
        }
      }
    }
    int l = 0,r =0,limit = noOfFlavours-1;
    set<int> s;
    for(;l<noOfCakes&&r<noOfCakes;l++){
      // see(limit);
      while(r<noOfCakes && limit>=0){
        if(s.find(cakes[r])==s.end()){
          s.insert(cakes[r]);
          limit--;
        }
        if(limit<0){
          s.erase(cakes[r]);
          limit+=2;
          r--;
          localAns = r-l+ 1;
          break;
        }
        r++;
      }
      // see(l);
      // see(r);
      // see(localAns);
      ans = max(localAns,ans);
      while(maxCount[l]<maxCount[l+1]&&l<noOfCakes){
        l++;
      }
      // look(s);
      s.erase(cakes[l-1]);
    }
    cout<<ans<<"\n";
  }
  return 0;
}