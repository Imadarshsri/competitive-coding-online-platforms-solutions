#include<bits/stdc++.h>
using namespace std;
//Macros
#define fo(n) for(auto i =0;i<n;i++)
#define fn(x,n) for(;x<n;x++)
#define pb push_back
#define mp make_pair
#define ll long long
#define ui uint64_t
#define see(x) cout<<#x<<" = "<<(x)<<"\n"
#define look(v) cout<<#v<<" : "; for(auto x:v) cout<<x<<" "; cout<<endl
#define vi vector<int> 
#define vui vector<uint64_t> 
#define vvi vector<vector<int>>
#define mi map<int>
#define rem 1000000007
vector<uint64_t> v;
int prime(ll x){
	int cnt = 0;
	for(ui j=2;j<=sqrt(x);j++){
		while(x%j==0){
			cnt++;
			x/=j;
		}
	}
	if(x>1) cnt++;
	return cnt;
}
int main(){
	int cases=0;
	cin>>cases;
	while(cases-->0){
		int x,k;
		cin>>x>>k;
		int divisors  = prime(x);
		if(divisors>=k){
			cout<<1<<"\n";
		}
		else cout<<0<<"\n";
	}
	return 0;
}