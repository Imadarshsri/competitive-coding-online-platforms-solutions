#include <iostream>
#include <vector>
using namespace std;

/*
AIM of BS
1) Find return criteria like maching the center element of array with ele to find in BS
2) Choose a criteria to discard half array portion
3) Choose desired half 
4) Repeat

Procedure :
1) Check the mid as minimum element
2) Min. always lies in unsorted portion (Observation)
3) Choose Unsorted Portiomn of array
4) Repeat
*/

//Anticlock-wise Rotation
// int rotation_count_anticlk(vector<int> &arr, int n){
//   if(n == 1) return 0;
//   int l = 0, r = n - 1;
//   int mid = l + (r - l)/2;
//   while(l <= r){
//     mid = l + (r - l)/2;
    // if(arr[(mid + n - 1)%n] >  arr[mid] && arr[mid] < arr[(mid + 1)%n]) 
    //   return ((n - mid) % n);

//     if(arr[mid] > arr[r]){
//       l = mid + 1;
//     }
//     else{
//       r = mid - 1;
//     }
//   }
//   return ((n - mid) % n);
// } 
//Clock-wise Rotation
int rotation_count_clk(vector<int> &arr, int n){
  if(n == 1) return 0;
  int l = 0, r = n - 1;
  int mid = l + (r - l)/2;
  while(l <= r){
    mid = l + (r - l)/2;
    if(arr[(mid + n - 1)%n] > arr[mid] && arr[mid] < arr[(mid + 1)%n]) 
      return mid;
    if(arr[mid] > arr[r]){//Right Side Unsorted
      l = mid + 1;
    }
    else{//Left Side Unsorted
      r = mid - 1;
    }
  }
  return mid;
} 

int main(){
  int n=1;
  cin>>n;
  vector<int> v(n);
  for(int i = 0 ; i < n; i++){
    cin>>v[i];
  }
  cout<<rotation_count_clk(v, n)<<endl;
  return 0;
}