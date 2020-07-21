#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
   uint64_t noOfFlowers = 1;
   cin>>noOfFlowers;
   vector<uint64_t> v(noOfFlowers);
   for(uint64_t i = 0; i < noOfFlowers; i++){
      cin>>v[i];
   }
   sort(v.begin(), v.end());
   cout<<v[noOfFlowers - 1] - v[0]<<" ";
   uint64_t flower1 = 0, flower2 = 0;

   for(uint64_t i = 0; i< noOfFlowers; i++){
      if(v[i] == v[0]) flower1++;
      else
          break;      
   }
   for(uint64_t i = noOfFlowers - 1; i >= 0; i--){
      if(v[i] == v[noOfFlowers - 1]) flower2++;
      else
          break;      
   }
   if(v[noOfFlowers - 1] == v[0]){
      cout<<(uint64_t)((uint64_t)flower1 * (uint64_t)(flower1 - 1))/ 2;
   }
   else
      cout<<flower1*flower2;
   return 0;
}