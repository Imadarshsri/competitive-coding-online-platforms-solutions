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
#define mi map<int>
#define rem 10e7
#define ui uint64_t

int main(){
    int cases=1;
    cin>>cases;
    // cout<<"ans\n";
    while(cases--){
        ui n=1;
        cin>>n;
        if(n&1){
            if(n==1){
                cout<<0<<"\n";
                continue;
            }
            n = (n>>1);
            cout<<n;
        }
        else{
            if(n==2){
                cout<<0<<"\n";
                continue;
            }
            n = (n>>1) -1;
            cout<<n;
        }
        cout<<"\n";
    }
    return 0;
}