#include<bits/stdc++.h>
using namespace std;
//Macros
#define fo(n) for(auto i =0;i<n;i++)
#define fn(x,n) for(;x<n;x++)
#define pb push_back
#define mp make_pair
#define ll long long (
#define look(x) cout<<#x<<" = "<<x
#define vi vector<int> 
#define vvi vector<vector<int>>
#define mi map<int>
#define rem 10e7

int main(){
		int cases=0;
		cin>>cases;
		vector<string> ans(cases);
		while(cases--){
			int n,flag=0;
			cin>>n;
			vector<pair<int,int>> rec;
			fo(n){
				int x,y=0;
				cin>>x>>y;
				rec.pb(mp(x,y));
			}
			// int i=1;
			fo(n){
				if(i==0){
					if(rec[i].second-rec[i].first >0){
						flag =1;
						break;
					}
				}
				else{
					int dp = rec[i].first - rec[i-1].first;
					int dc = rec[i].second - rec[i-1].second;
				if(dp<0||dc<0){
					flag=1;
					break;
				}
				else if(dp - dc<0){
					flag=1;
					break;						
				}
				}
			}
			if(flag==1)
				cout<<"NO\n";
			else 
				cout<<"YES\n";
			rec.clear();
		}
		return 0;
}