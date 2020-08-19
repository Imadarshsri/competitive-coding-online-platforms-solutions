#include<iostream>
using namespace std;
///Printing Pattern  n = 5
//         1
//       1 2 3
//     1 2 3 4 5
//   1 2 3 4 5 6 7
// 1 2 3 4 5 6 7 8 9

int main(){
  int n;
  cin>>n;
  int space = 0;
  for(int i = 1; i<= n; i++){
    for(int j = 0; j < n - i; j++){
      cout<<"  ";
    }
    for(int j = 1; j< i*2; j++){
      cout<<j % 10<<" ";
    }
    cout<<"\n";
  }
  return 0;
}