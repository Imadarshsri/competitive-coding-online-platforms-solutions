#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(pair<int, char> &a, pair<int, char> &b){
   return a.first > b.first;
}

int main(){
   // freopen("input.txt","r",stdin); 
   // freopen("output.txt","w",stdout);
   int n = 1, k = 1;
   cin>>n>>k;
   map<char,int> cardCharCount;
   for(int i =0 ;i < n; i++){
      char x;
      cin>>x;
      cardCharCount[x]++;
   }
   uint64_t maxEarning = 0;
   vector<pair<int, char>> v;
   for(auto x: cardCharCount) v.push_back(make_pair(x.second, x.first));
   sort(v.begin(), v.end(), comp);
   // for(auto x : v){
   //    cout<<x.first <<" : "<<x.second<<"\n";
   // }
   for(int i = 0;i < v.size() && k > 0; i++){
      int x = v[i].first;
      if(x >= k){
         maxEarning += (uint64_t)k*k;
      }
      else{
         maxEarning += (uint64_t)x*x;
         // k -= x;
      }
      k -= x;
   }
   cout<<maxEarning;
   return 0;
}