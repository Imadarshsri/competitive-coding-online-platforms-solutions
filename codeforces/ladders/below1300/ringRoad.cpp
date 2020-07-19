#include<iostream>

using namespace std;

int main(){
   int houses = 2, tasks = 1;
   cin>>houses>>tasks;
   int n = tasks;
   int x = 0, y = 0;
   uint64_t cost = 0;
   while(n--){
      cin>>y;
      y--;
      if(x > y){
         cost += houses - x + y;
      }
      else{
         cost += y - x;
      }
      x = y;
   }  
   cout<<cost<<"\n";
}