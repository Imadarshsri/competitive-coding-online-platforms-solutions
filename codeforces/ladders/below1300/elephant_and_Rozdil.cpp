#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
   int n;
   cin>>n;
   vector<pair<int,int>> towns;
   for(int i =0 ;i <n; i++){
      int x;
      cin>>x;
      towns.push_back(make_pair(x, i+1));
   }
   sort(towns.begin(), towns.end());
   int ans = towns[0].first;
   int idx = 1;
   for(int i = 1; i < n; i++){
      if(towns[i].first == ans){
         cout<<"Still Rozdil\n";
         return 0;
      }
   }
   cout<<towns[0].second<<"\n";
   return 0;
}