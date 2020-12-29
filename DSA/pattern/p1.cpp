#include<iostream>
using namespace std;
///Printing Pattern (n = 5)
// * * * * *
//     * * * *
//         * * *
//             * *
//                 * 
int main(){
  int n;
  cin>>n;
  int m = n, space = 0;
  for(int i =0; i< n; i++, m--,space+=2){
    for(int j =0; j< space; j++){
      cout<<"  ";
    }
    for(int j = m; j > 0; j--){
      cout<<"* ";
    }
    cout<<"\n";
  }
  return 0;
}