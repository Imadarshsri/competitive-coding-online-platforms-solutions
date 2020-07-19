#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
   int totalTVs = 2, tvBobCanCarry = 1;
   cin>>totalTVs>>tvBobCanCarry;
   uint64_t cost = 0;
   vector<int> v(totalTVs);
   for(int i =0 ;i <totalTVs; i++){
      cin>>v[i];
   }
   sort(v.begin(), v.end());
   for(int i =0 ;i <tvBobCanCarry && v[i] < 0; i++){
      cost+=abs(v[i]);
   }
   cout<<cost<<"\n";
}