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
#define rem (10e9 + 7)

int main(){
	int cases=0;
	cin>>cases;
	while(cases-->0){
		int n=0,flag=0;
		cin>>n;
		vi v(n);
		for(auto i=0;i<n;i++){
			cin>>v[i];
		}
		for(auto i=0;i<n;i++){
			if(v[i]==1){
				int k=i+6;
				i++;
				for(;i<k&&i<n;i++){
					if(v[i]==1){
						cout<<"NO"<<"\n";
						flag =1;
						break;
					}
					if(flag==1) break;
				}
				i--;
			}
			if(flag==1) break;
		}
		v.clear();
		if(flag==1) continue;
		cout<<"YES"<<"\n";
	}
	return 0;
}