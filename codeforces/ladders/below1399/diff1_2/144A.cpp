#include<iostream>
#include<vector>

using namespace std;
int main(){
   int n;
   vector< int > v;
   cin>>n;
   for(int i = 0; i < n;i++){
      int x;
      cin>>x;
      v.push_back(x);
   }
   int min = 0, max = 0;
   for(int i = 0; i < n;i++){
      if(v[i] <= v[min]){
         // cout<<"min cj\n";
         min = i;
      }
      if(v[i] > v[max]){
         // cout<<"miav cj\n";

         max = i;
      }
   }
   // cout<<min << " --- "<<max<<endl;
   if(min < max){
      cout <<((max) + (n - 1 - min) - 1)<<"\n";
   }
   else{
      cout <<((max) + (n  - 1 - min))<<"\n";
   }
}