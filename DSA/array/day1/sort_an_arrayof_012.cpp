#include<bits/stdc++.h>
using namespace std;

// Problem link: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0
// Solution: https://www.youtube.com/watch?v=oaVa-9wmpns&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2

class Solution {
public:
    void sortColors(vector<int>& arr) {
      int len = arr.size();
      int low = 0, mid = 0, high = len-1;
      while(mid<=high){
        if(arr[mid] == 0){
          swap(arr[mid], arr[low]);
          low++; mid++;
        }
        else if(arr[mid] == 1) mid++;
        else{
          swap(arr[mid], arr[high]);
          high--;
        }
      }
    }
    // void sortColors(vector<int>& arr) {
    //   int len = arr.size();
    //   int zero = 0, ones = 0;
    //   for(int i =0; i< len ;i++){
    //     if(arr[i] == 0) zero++;
    //     else if (arr[i] == 1) ones++;
    //   }
    //   int i = 0;
    //   for(i = 0; i < len; i++){
    //     if(zero-->0)
    //       arr[i] = 0;
    //     else if (ones-- > 0)
    //       arr[i] = 1;
    //     else arr[i] = 2;
    //   }
    // }
  
};