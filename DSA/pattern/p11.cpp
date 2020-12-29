#include<iostream>
using namespace std;
///Printing Pattern  n = 5
//      1
//     1 1
//    1 2 1
//   1 3 3 1
//  1 4 6 4 1
// 1 5 10 10 5 1

int main(){
  int n;
  cin>>n;
  int num = 1;
  for(int i = 1 ; i <= n+1; i++, num++){

    for(int j = 0; j <= n - i; j++) cout<<" ";
        if(i == 1){
      cout<<"1\n";
      continue;
    }
    int j, k;
    for(j = 0, k = 0; k < (i +1)/2 ; j+=i - 1, k++){
      if(j == 0) 
        cout<<(j + 1)<<" ";
      else
      cout<<j %10<<" ";
    }
    if (i&1) {j-= 2 * (i - 1) ;}

    else{ j-= i -1; }
    for(  k = 0; k < i/2 ; j-=i - 1, k++){
        if(j == 0) 
        cout<<(j + 1)<<" ";
      else
      cout<<j %10<<" ";
    }

    cout<<"\n";
  }
  return 0;
}