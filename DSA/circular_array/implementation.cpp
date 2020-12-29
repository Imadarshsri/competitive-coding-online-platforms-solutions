// pROGRAM TO IMPLEMTNT CIRCULAR ARRAY 
// Given an array of numbers and an integer
// print the complete array from the index in a complete manner

#include<iostream>
using namespace std;

int main(){
  int size = 1, idx;
  cin>>size>>idx;
  idx--;
  int arr[size];
  for(int i = 0; i< size; i++){
    cin>>arr[i];
  }

  for(int i = idx; i< size + idx; i++){
    cout<<arr[i%size]<<" ";
  }
}