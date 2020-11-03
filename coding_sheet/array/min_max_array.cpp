#include <iostream>
#include <vector>


using namespace std;
///Problem statement: Find minimum and maximum of an array with minimum no. of Comparisions.
//Tutorial : https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
//No. of Comparisions: 3(n - 1)/2;
class Solution{
   public:
   int max;
   int min;
   int compCount;
   Solution(vector<int> arr){
      compCount = 0;
      int n = arr.size();
      int i = 0;
      if(n == 1){
         max = arr[0];
         min = arr[0];
         return;
      }
      if(n&1){
         max = arr[0];
         min = arr[0];
         i = 1;
      }
      else{
         compCount++;
         if(arr[0] > arr[1]){
            max = arr[0];
            min = arr[1];
         }
         else{
            max = arr[1];
            min = arr[0];
         }
         i += 2;
      }

      while(i < n - 1){
         compCount++;
         if(arr[i] > arr[i+1]){
            compCount++;
            if(arr[i] > max){
               max = arr[i];
            }
            compCount++;
            if(arr[i+1] < min){
               min = arr[i + 1];
            }
         }
         else{
            compCount++;
            if(arr[i + 1] > max) max = arr[i+1];
            compCount++;
            if(arr[i] < min) min = arr[i];
         }
         i+=2;
      }
   }
};

int main(){
   int n = 1;
   cin >> n;
   vector<int> v(n);
   for(int i = 0; i < n; i++){
      cin >> v[i];
   }

   Solution s = Solution(v);
   cout<< "Max: " << s.max << " Min: " << s.min << "\nNo. of Comparisions: " << s.compCount << "\n";
}