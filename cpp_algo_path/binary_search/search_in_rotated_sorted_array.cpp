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
1) Check the mid element for x
2) check whether x lies in sorted or unsorted half
3) Choose the portion apt.
4) Repeat
*/

//Binary Search
int rotation_count_clk(vector<int> &arr, int n, int x){
  if(n == 1) return 0;
  int l = 0, r = n - 1;
  int mid = l + (r - l)/2;
  while(l <= r){
    mid = l + (r - l)/2;
    if(arr[mid] == x) 
      return mid;
    if((arr[mid] > arr[r])){ //Right Side Unsorted
      if((arr[mid] > x && arr[l] <= x)) {
        r = mid - 1;
      }
      else 
        l = mid + 1;
    }
    else{ //Left Side Unsorted
      if((arr[mid] < x && arr[r] >= x))
        l = mid + 1;
      else 
        r = mid - 1;
    }
  }
  return mid;
} 

int main(){
  int n = 1, x = 1;
  cin>>n;
  vector<int> v(n);
  for(int i = 0 ; i < n; i++){
    cin>>v[i];
  }
  cin>>x;
  cout<<rotation_count_clk(v, n, x)<<endl;
  return 0;
}