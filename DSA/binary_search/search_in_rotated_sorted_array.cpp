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

//Method 1
int search(vector<int> &arr, int n, int x){
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

//Method 2
//Binary Search
int binary_search(vector<int> &arr, int l , int r, int x){
  while(l <= r){
    int mid = l + (r - l)/2;
    if(arr[mid] == x){
      return mid;
    }
    else if(arr[mid] > x){
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  return -1;
}
//Find min in Rotated Sorted Array
int find_min(vector<int> &arr, int l, int r){
  int n = arr.size();
  if( n == 1) return arr[0];
  while(l <= r){
    int mid = l + (r - l)/2;
    if(arr[(mid + n - 1) % n] > arr[mid] && arr[mid] < arr[(mid + 1) % n]){
      return mid;
    }
    else if(arr[mid] > arr[r]){
      l = mid + 1;
    }
    else{
      r = mid - 1;
    }
  }
  return -1;
}

int main(){
  int n = 1, x = 1;
  cin>>n;
  vector<int> v(n);
  for(int i = 0 ; i < n; i++){
    cin>>v[i];
  }
  cin>>x;
  //Method 1
  // cout<<search(v, n, x)<<endl;
  //Method 2
  int idx = find_min(v,0,n-1);
  int ans1 = binary_search(v, 0, idx - 1, x);
  int ans2 = binary_search(v, idx, n - 1, x);
  int ans = (ans1 == -1) ? ans2 : ans1;
  cout<<ans<<endl;
  return 0;
}