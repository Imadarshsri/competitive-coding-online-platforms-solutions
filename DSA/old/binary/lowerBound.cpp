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
   int l = 0, r = n - 1;
   int mid;
   while(l<r){
      // cout<<"before : "<<l<<" "<<r<<"\n";
      mid = l + ((r - l)/2);
      if(arr[mid] >= x){
         r = mid;
         mid = r;
      }
      else{
         l = mid + 1;
         mid = l;
      }
      // cout<<"after : "<<l<<" "<<r<<"\n";
   }
   //X at index
   cout<<"Lower bound index: "<<mid<<"\n";
   return 0;
}