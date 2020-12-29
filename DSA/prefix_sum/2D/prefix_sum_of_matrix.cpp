#include <iostream>
using namespace std;

int main(){
   int r = 1, c = 1;
   cin>>r>>c;
   int arr[r][c], pre[r][c];
   
   //Input
   for(int i = 0;i < r; i++){
      for(int j = 0; j < c; j++){
         cin>>arr[i][j];
      }
   }
   //initializing and handling corner cases
   pre[0][0] = arr[0][0];
   for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
         if(i == 0 && j == 0) continue;

         if(j == 0 && i > 0 && i < r) 
            pre[i][j] = pre[i - 1][j] +  arr[i][j]; 

         else if(i == 0 && j > 0 && j < c)
            pre[i][j] = pre[i][j - 1] +  arr[i][j]; 

         else
            pre[i][j] = pre[i][j - 1] +  pre[i - 1][j] - pre[i - 1][j -1] + arr[i][j];    
      }
   }

   for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
         cout<<pre[i][j] << " ";
      }
      cout<<"\n";
   }
   return 0;
}