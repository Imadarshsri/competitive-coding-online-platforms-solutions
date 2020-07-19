#include<iostream>
using namespace std;
int main(){
   int n = 1;
   cout<<"Enter Size of array\n";
   cin>>n;
   int arr[n];
   cout<<"Enter elements of array\n";
   for(int i = 0; i < n ; i++) cin>>arr[i];
   int x = 1;
   cout<<"Enter ele to search\n";
   cin>>x;
   //BS
   int k = 0;
   for(int b = n/2; b >= 1; b/=2){
      // cout<<"b = "<<b<<"\n";
      while((k+b) < n && arr[k+b] <= x) {
         k+= b;
      // cout<<"k = "<<k<<"\n";
      }
   }

   //X at index
   if(arr[k] == x)
      cout<<x<<" is at index : "<<k<<"\n";
   else 
      cout<<x<<" not found\n";
   return 0;
}