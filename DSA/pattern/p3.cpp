#include<iostream>
using namespace std;
///Printing Pattern (n = 5)
//             *
//          *  *
//       *  *  *
//    *  *  *  *
// *  *  *  *  * 
//    *  *  *  *
//       *  *  *
//          *  *
//             *
int main(){
  int n;
  cin>>n;
  int m = n, space = 0;
  for(int i = 1; i <= n; i++, m--,space+=2){
    for(int j = m - 1; j > 0; j--){
      cout<<"  ";
    }
    for(int j = 0; j < i; j++){
      cout<<"* ";
    }
    cout<<"\n";
  }
  for(int i = n - 1; i > 0; i--){
    for(int j = n - i ; j ; j--){
      cout<<"  ";
    }
    for(int j = 0; j < i; j++){
      cout<<"* ";
    }
    cout<<"\n";
  }
  return 0;
}