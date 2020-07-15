#include<bits/stdc++.h>
using namespace std;
//Macros
#define fo(n) for(auto i =0;i<n;i++)
#define fn(x,n) for(auto i =x;i<n;i++)
#define pb push_back
#define mp make_pair
#define ll long long (
#define look(x) cout<<#x<<" = "<<x
#define vi vector<int> 
#define vvi vector<vector<int>>
#define mi map<int>
#define pi pair<int,int>
#define rem 10e7

int main(){
    int cases = 1;
    cin>>cases;
    while (cases--)
    {
        int n=1;
        cin>>n;
        vi v(n);
        vector<pi> p;
        fo(n){
          cin>>v[i];
        }
        sort(v.begin(),v.end());
        // vi bc(n) = {},bc1=INT_MIN;
        int flag = 1;
        for(int k=0;flag==1;k++){
          fo(n){
          if(i==0){
            cout<<"xxcxc -- "<<abs(v[i])<<"\n";
            p.pb(mp(0,v[i]));
            // bc  = max(bc,abs(v[i]));
            //  if(k==0)
            v[i] = 0;
          }
          else{
            // bc  = max(bc,abs(v[i]-v[i-1]));
            p.pb(mp(abs(v[i]-v[i-1]),v[i]));
            // if(k==0)
            v[i] = abs(v[i]-v[i-1]);
          }

        }
          sort(p.begin(),p.end());
          int q =0;
          for(auto x: p){
            if(v[q]==x.first) flag=0;
            else{
              flag = 1;
            }
            q++;
          }
        }
        for(auto x : p){
          cout<<x.first<<" "<<x.second<<"\n";
        }
        // for(auto x : v){
        //   cout<<x<<" "<<"\n";
        // }

        cout<<"check";
        for(auto x : p){
          // x.second = 0;
          cout<<x.second<<" ";
        }
        cout<<"\n";
    }
    return 0;
}