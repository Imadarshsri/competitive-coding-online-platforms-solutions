#include <iostream>
using namespace std;
int main(){
   uint64_t n = 1,k = 1;
   cin>>n>>k;
   uint64_t i = 0;
   if(k > ((n/2)+(n&1))){
      //evens
      k-=((n/2)+(n&1));
      cout<<(2*k)<<"\n";
   }
   else{
      i = 1;
      cout<<(2*k) - 1<<"\n";
   }
   return 0;
}