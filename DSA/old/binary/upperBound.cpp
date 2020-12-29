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
   int mid = 0;
   while(l<r){
      // cout<<"before : "<<l<<" "<<r<<"\n";
      mid = l + ((r - l)/2);
      if(arr[mid] <= x){
         l = mid + 1;
         mid = l;
      }
      else{
         r = mid;
         mid = r;
      }
      // cout<<"after : "<<l<<" "<<r<<"\n";
      if(l == r && l == n -1 && x >= arr[l]) {
         l = l + 1;
      }
   }
   //X at index
   cout<<"Upper bound (Last Index) index: "<<l - 1<<"\n";
   return 0;
}
