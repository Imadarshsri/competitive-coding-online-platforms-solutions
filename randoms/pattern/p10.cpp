#include<iostream>
using namespace std;
///Printing Pattern  n = 5
//         0
//       4 0 4
//     3 4 0 4 3
//   2 3 4 0 4 3 2
// 1 2 3 4 0 4 3 2 1

int main(){
  int n;
  cin>>n;
  int space = 0;
  for(int i = 0 ; i< n; i++){
    for(int j = n - i + 1; j>0 ;j--){
      cout<<"  ";
    }
    //forward print
    for(int j = n - i; j < n; j++ ){
      cout<<j<<" ";
    }
    cout<<"0 ";
    //backward print
    for(int j = n - 1; j >= n - i; j-- ){
      cout<<j<<" ";
    }
    cout<<"\n";
  }
  return 0;
}