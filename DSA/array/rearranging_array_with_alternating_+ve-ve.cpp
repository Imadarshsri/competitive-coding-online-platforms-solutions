#include <iostream>

using namespace std;
#define N 1000

// Here we are dividing this problem into 2 parts:
// 1) shifting all -ves to the end of array
// 2) then rearranging them according to the problm
// This approach does not follow the order of elements
// T(n) -> O(n)
void  solve(int arr[], int n){

  int l = 0, r = n-1;
  
  while(l <= r){
    if(arr[l] < 0 && arr[r] > 0)
      swap(arr[l],arr[r]);
    if(arr[l] > 0) l++;
    if(arr[r] < 0) r--;
  }
  r = 0;
  while(l < n && r < n && r < l){
    if(arr[l] < 0 && arr[r] > 0){
      swap(arr[l],arr[r]);
      r+=2; l++;
    }
    if(arr[l] > 0){
      l++;
    }
    if(r & 1 == 1 || arr[r] < 0){
      r++;
    }
  }
}

// Here we are simply performing Instertion Sort to rearrange the elements
// T(n) : O(n^2)
// You can also say that we are mantaining order of the elements and following below approach:
// 1) First find misplaced element
// 2) then find the element of opposite sign which can replace misplaced element 
// 3) Simply right rotate all the elements of these subarray including these 2 elements as well
// 4) follow 1-3 untill reaches end of the array
void solve2(int arr[], int n){
  int l = 0, r = 0;
  for(int i = 0; i < n && r < n; i++){
    if(((i & 1) == 0) && (arr[i] > 0)){
      r = i+1;
      while(arr[r] > 0 && r < n){
        r++;
      }
      if(r >= n) break;
      int temp = arr[r];
      while(r > i){
        arr[r] = arr[r-1];
        r--;
      }
      arr[i] = temp;
    }
    else if(((i & 1) == 1) && (arr[i] < 0)){
      r = i+1;
      while(arr[r] < 0 && r < n){
        r++;
      }
      if(r >= n) break;
      int temp = arr[r];
      while(r > i){
        arr[r] = arr[r-1];
        r--;
      }
      arr[i] = temp;
    }
  }
}
int main(){
  int arr[N];
  int n;
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
  solve2(arr,n);
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }
}