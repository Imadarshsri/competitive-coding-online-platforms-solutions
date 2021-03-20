#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

/// Problem: https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/
/// Solution: https://www.youtube.com/watch?v=5nMGY4VUoRY&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=3
// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

// int *findTwoElement(int *arr, int n) {
//     set<int> s;
//     int ans[2];
    
    // int *ans = (int *)malloc(sizeof(int)*2);
//     for(int i = 1; i <= n; i++){
//         s.insert(i);
//     }
    
//     for(int i = 0; i < n; i++){
//         if(s.find(arr[i]) != s.end()){
//             s.erase(arr[i]);
//         }
//         else{
//             ans[0] = arr[i];
//         }
//     }
//     // cout<<"->"<<*s.begin()<<"\n";
//     ans[1] = *(s.begin());
//     return ans;
// }
int *findTwoElement(int *arr, int n) {
    int *ans = (int *)malloc(sizeof(int)*2);
    ans[0] = 0;
    ans[1] = 0;
    // using xor method
    int xorr = 0;
    for(int i = 1; i <= n; i++){
        xorr ^= i;
    }
    
    for(int i = 0; i < n; i++){
        xorr ^= arr[i];
    }
    // now xorr = x^y;
    int set_bit_no = xorr & ~(xorr - 1);
    // Divide Array in 2 buckets
    for(int i = 0; i < n; i++){
        if(set_bit_no & arr[i])
            ans[0] ^= arr[i];

        else
            ans[1] ^= arr[i];
    }
    // Divide (1...N) in 2 buckets
    for(int i = 0; i < n; i++){
        if(set_bit_no & arr[i])
            ans[0] ^= i;

        else
            ans[1] ^= i;
    }

    // now we get ans[0] -> Missing No. & ans[1] -> Repeating NO.
    return ans;
}

int main(){
  int n = 0;
  cin>>n;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
  int *a = findTwoElement(arr, n);
  cout<<a[0]<<" "<<a[1]<<"\n";
  return 0;
}