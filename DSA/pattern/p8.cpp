#include<iostream>
using namespace std;
///Printing Pattern  n = 5
//         1
//       2 0 2
//     3 0 0 0 3
//   4 0 0 0 0 0 4
// 5 0 0 0 0 0 0 0 5

int main(){
  int n;
  cin>>n;
  int space = 0;
  for(int i = 1; i<= n; i++){
    for(int j = 0; j < n - i; j++){
      cout<<"  ";
    }
    for(int j = 1; j< i*2; j++){
      if( j == 1 || j== (2*i - 1)) cout<<i<<" ";
      else
        cout<<"0 ";
    }
    cout<<"\n";
  }
  return 0;
}