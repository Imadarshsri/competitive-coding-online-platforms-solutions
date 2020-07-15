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
vector<string> al(26); 
int main(){
    int cases=1;
    cin>>cases;
    fo(26){
        al[i] = (char)97 +i;
    }
    // cout<<"Caheck\n";
    // for(auto x:al){
    //     cout<<x<<" ";
    // }
    // // cout<<"ams";
    // cout<<"ans\n";
    while(cases--){
        int a=1,b=1,n=1;
        string str= "";
        cin>>n>>a>>b;
        for(int i=0;i<n;i++){
           str += al[i%b];
            // if(i==b-1){
            //     i=-1;
            // }
       }
        cout<<str<<"\n";
        str.clear();
    }
    return 0;
}