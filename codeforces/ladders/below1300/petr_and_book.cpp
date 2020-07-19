#include<iostream>
using namespace std;
int main(){
   int pages;
   cin>>pages;
   int days[7], sum =0;
   for(int i = 0; i < 7 ; i++){
      cin>>days[i];
      sum +=days[i];
   }
   int temp = pages;
   pages %= sum;
   if(pages == 0){
      pages = temp;
   }
   while (pages > 0)
   {
       for(int i = 0; i < 7; i++){
      pages -= days[i];
      if(pages <= 0) {
         cout<<i+1<<"\n";
         return 0;
      }
   }
   }
   
   return 0;
}