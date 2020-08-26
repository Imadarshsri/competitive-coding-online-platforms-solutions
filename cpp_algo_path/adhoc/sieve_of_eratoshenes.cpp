#include <bits/stdc++.h>
using namespace std;

int main(){
  int n = 1;
  cin>>n;
  int arr[n + 1];
  memset(arr, 0, sizeof(arr));
  for(int i = 2; i <= n; i++){
    if(arr[i] == 0){
      for(int j = i*i; j <= n; j+=i){
        if(j % i == 0){
          arr[j] = 1;
        }
      }
    }
  }
  for(int i = 2; i < n; i++){
    if(arr[i] == 0)
    cout<<i<<" ";
  }
  return 0;
}