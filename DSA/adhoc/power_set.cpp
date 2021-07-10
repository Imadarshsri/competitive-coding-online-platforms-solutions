#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
void solve(){
   int n;
   cin>>n;
   int v[n+1];
   for(auto i = 0; i <= n; i++) {
      v[i] = i;
   }
   uint64_t powerSetCount = pow(2, n);
   for(auto setNo = 0; setNo < powerSetCount; setNo++) {
      vector<int> subset;
      for(int i = 0; i <= n; i++) {
         if((1 << i) & setNo)
            subset.push_back(v[i]);
      }
      for(auto x: subset) 
         cout<<x<<" ";
      cout<<endl;
   }
}

int main(){
   solve();
   return 0;
}