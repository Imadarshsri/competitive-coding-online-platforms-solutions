#include <iostream>
using namespace std;

int main(){
   freopen("input.txt","r",stdin); 
   freopen("output.txt","w",stdout);
   int n = 1, m = 1;
   cin>>n>>m;
   if(n >= m){
      for(int i = 0; i<m;i++){
         cout<<"BG";
      }
      for(int i = 0; i<(n - m);i++){
         cout<<"B";
      }
   }

   else{
      for(int i = 0; i < n;i++){
         cout<<"GB";
      }
      for(int i = 0; i < (m - n);i++){
         cout<<"G";
      }
   }
   return 0;
}