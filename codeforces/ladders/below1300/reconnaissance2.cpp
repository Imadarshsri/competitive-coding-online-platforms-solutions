#include <iostream>
#include <vector>

using namespace std;
int main(){
   int soldiers;
   cin>>soldiers;
   vector<int> v(soldiers);
   for (int i = 0; i< soldiers; i++){
      cin>>v[i];
   }

   int minimal = INT32_MAX;
   int x = 0, y = 0;
   for(int i = 0; i < soldiers - 1 ; i++){
      
      if(minimal > abs(v[i] - v[i+1])){
         x = i +1;
         y = i + 2;
         minimal = abs(v[i] - v[i+1]);
      }
      // cout<<"x= "<<x<<"y = "<<y<<"\n";
   }
   if(minimal > abs(v[(soldiers - 1)] - v[0])){
         x = soldiers;
         y = 1;
         minimal = abs(v[(soldiers - 1)] - v[0]);
      }
   cout<<x<<" "<<y<<"\n";
   return 0;
}