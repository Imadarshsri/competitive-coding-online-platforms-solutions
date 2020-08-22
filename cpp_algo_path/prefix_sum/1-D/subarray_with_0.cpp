#include <iostream>
#include <string.h>
#include <map>
using namespace std;

/*
The Approach is simple if we will find the prefix sum of 
each element of array if this sum aready exists before the there 
exists a subarray with sum 0 else it does n't exist.
*/

typedef long long ll;

void solve(){
   ll n = 1;
   cin>>n;
   ll arr[n];
   memset(arr, 0, sizeof(arr)); 
   map<ll,ll> m;

   for(ll i = 0; i < n; i++){
      cin>>arr[i];
   }

   ///Tackling Edge cases
   m[0] = 1;
   
   ll sum = 0;
   for(int i = 0; i < n; i++){
      // if(arr[i] == 0){
      //    //  m[0] = i + 1;
      //    cout<<"Yes"<<i+1<<" "<<i+1;
      // }
      sum += arr[i];
      if(m.find(sum) == m.end()){
         m[sum] = i + 1;
      }
      else{
         cout<<"Yes\n";
         // cout<<m[sum] + 1<<" "<<i + 1<<"\n";
         return;
      }
   }
   cout<<"No\n";
}

int main() {
	int cases = 1;
	cin>>cases;
	while(cases--){
      solve();
	}
	return 0;
}