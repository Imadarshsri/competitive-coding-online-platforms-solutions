#include <iostream>
#include <string.h>
using namespace std;

typedef long long ll;

void solve(){
   ll n = 1;
   cin>>n;
   ll arr[n];
   memset(arr, 0, sizeof(arr)); 
   ll sum = 0;
   for(ll i = 0; i < n; i++){
      cin>>arr[i];
      sum += arr[i];
   }
   ll leftsum = 0;
   for(ll i = 0; i < n; i++){
      sum -= arr[i];
      // cout<<leftsum <<"  -x x x-  "<<sum<<"\n";
      if(leftsum == sum){
         cout<<i + 1<<"\n";
         return;
      }
      leftsum += arr[i];
   }
   cout<<"-1\n";
}

int main() {
	int cases = 1;
	cin>>cases;
	while(cases--){
      solve();
	}
	return 0;
}