#include<iostream>
#include<limits.h>
typedef long long int lli;
using namespace std;

void solve(){
	int n = 1;
	cin>>n;
	int arr[n];
	int max = INT_MIN, min = INT_MAX;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		if(arr[i] > max) max = arr[i];
		if(arr[i] < min) min = arr[i];
	}
	cout<<(long long int)2 * (long long int)((long long int)max - (long long int)min)<<"\n";
}
int main(){
	 int t = 0;
	 cin>>t;
	 while(t--)
		solve();
	return 0;
 }