#include<bits/stdc++.h>
using namespace std;
//Macros
#define fo(n) for(auto i =0;i<n;i++)
#define fn(x,n) for(auto i =x;i<n;i++)
#define pb push_back
#define mp make_pair
#define ll long long
#define look(x) cout<<#x<<" = "<<x
#define vi vector<int> 
#define vvi vector<vector<int>>
#define mi map<int,int>
#define rem 10e7
#define ui uint64_t
// vector<string> al(26); 
int main(){
    int cases=1;
    cin>>cases;
    while(cases--){
        ui n=1,mx=0;
        cin>>n;
        mi m;
        set<int> s;
        fo(n){
          int x;
          cin>>x;
          m[x]++;
          s.insert(x);
          mx = mx>m[x]?mx:m[x];
        }

        ui sz = s.size();
        auto a = min(sz-1,mx);
        auto b = min(sz,mx-1);
        cout<<max(a,b)<<"\n";
    }
    return 0;
}