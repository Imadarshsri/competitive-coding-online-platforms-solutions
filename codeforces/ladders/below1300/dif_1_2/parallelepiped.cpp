#include <iostream>
#include <cmath>
using namespace std;
int main(){
   uint64_t x,y,z;
   cin>>x>>y>>z;
   uint64_t ans = (uint64_t)sqrt((uint64_t)(x*y*z));
   // cout<<"ans "<<ans<<"vs";
   cout<<(4*(ans/x)) + (4*(ans/y)) + (4*(ans/z))<<"\n";
   return 0;
}