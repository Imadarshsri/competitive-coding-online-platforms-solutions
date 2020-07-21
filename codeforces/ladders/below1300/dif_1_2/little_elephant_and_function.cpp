#include<iostream>

using namespace std;

int main(){
   int numbers = 1;
   cin>>numbers;
   //Generating Permutation
   cout<<numbers<<" ";
   for(int i = 1; i < numbers; i++){
      cout<<i<<" ";
   }
   cout<<"\n";
}