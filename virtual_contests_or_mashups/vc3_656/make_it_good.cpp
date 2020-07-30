#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void solve(){
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i =0; i< n; i++){
      cin>>v[i];
   }
   int uphilMax = v[n-1], i = n - 1;
   for(i = n-1; i>=0; i--){
      if(v[i]<uphilMax){
         // cout<<"vi => "<<v[i]<<"\n";
         i++;
         break;
      }
      uphilMax = v[i];
   }

   for( ; i >= 0; i--){
      if(v[i] > uphilMax) {
         // cout<<"vi => "<<v[i]<<"\n";
         i++;
         break;
      }
      uphilMax = v[i];
   }
   cout<<max(i,0)<<"\n";
}

int main(){
   int cases= 1;
   cin>>cases;
   while(cases--){
      solve();
   }
   return 0;
}