#include<iostream>
using namespace std;
# define RANGE 256
int main(){
  int hash[RANGE]{0}, phash[RANGE]{0};
  int n = 7;
  int arr[] = {1,2,9,4,1,2,0};
  //Counting
  for(int i = 0; i < n; i++){
    hash[arr[i]]++;
  }
  phash[0] = hash[0];
  for(int i = 1; i < RANGE; i++) phash[i] = phash[i-1] + hash[i];


  for(int i = 0; i < RANGE; i++){
    while(hash[i]-->0){
      // cout<<"x-->"<<i<<" pos::"<<phash[i] - 1<<endl;
      arr[phash[i] - 1] = i;
      phash[i]--;
    }
  }

  cout<<"Sorted Array: ";
  for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
  cout<<endl; 
}
