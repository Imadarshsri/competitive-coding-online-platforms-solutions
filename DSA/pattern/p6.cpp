#include<iostream>
using namespace std;
///Printing Pattern  n = 5
//         *          
//       * *        
//     *   *      
//   *     *    
// * * * * *  

int main(){
  int n;
  cin>>n;
  int space = 0;
  for(int i = 1; i < n; i++){
    for(int j = n - i; j > 0; j--){
      cout<<"  ";
    }
    for(int j = 0; j < i; j++){
      if(j == 0 || j == i - 1)
        cout<<"* ";
        else cout<<"  ";
    }
    cout<<"\n";
  }
  for (int i =0; i< n; i++) cout<<"* ";
  return 0;
}