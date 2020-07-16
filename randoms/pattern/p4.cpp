#include<iostream>
using namespace std;
///Printing Pattern  n = 3
// * * *   * * *
// * *       * * 
// *           *

// *           *
// * *       * *
// * * *   * * *

/// n = 4
// * * * *  * * * *
// * * *      * * *
// * *          * *
// *              *
// *              *
// * *          * *
// * * *      * * *
// * * * *  * * * *

/// n = 5
// * * * * *   * * * * *     
// * * * *       * * * *
// * * *           * * *
// * *               * *
// *                   *

// *                   *
// * *               * *
// * * *           * * *
// * * * *       * * * *
// * * * * *   * * * * *

int main(){
  int n;
  cin>>n;
  int space = n&1;
  for(int i = n, k = n; i > 0; i--, k--, space+=4){
    for(int j = k; j >0; j--){
        cout<<"* ";
    }
    for(int j = 0;j<space;j++){
      cout<<" ";
    }
    for(int j = k; j> 0;j--) cout<<" *";
    cout<<"\n";
  }
  space-=4;
  if(n&1) cout<<"\n";
  for(int i = n, k = n; i > 0; i--, k--, space-=4){
    for(int j = n - k; j >= 0; j--){
        cout<<"* ";
    }
    for(int j = 0;j<space;j++){
      cout<<" ";
    }
    for(int j = n - k; j >= 0;j--) cout<<" *";
    cout<<"\n";
  }
  return 0;
}