#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
  fastio;
  int cases = 1;
  cin>>cases;
  while(cases--){
    int k;
    char chess[8][8];
     for(int i = 0;i < 8 ;i++){                           
      for(int j = 0; j < 8 ;j++){
        chess[i][j] = '-';
      }
    }
    cin>>k;
    chess[0][0] = 'O';
    k--;
    for(int i = 0;i < 8 && k;i++){
      for(int j = 0; j < 8 && k;j++){
        if(chess[i][j] == '-'){ chess[i][j] = '.'; k--; }
      }
    }
    for(int i = 0;i < 8;i++){
      for(int j = 0; j < 8;j++){
        if(chess[i][j] == '-') chess[i][j] = 'X';
      }
    }
    for(int i = 0;i < 8 ;i++){
      for(int j = 0; j < 8 ;j++){
        cout<<chess[i][j];
      }
      cout<<"\n";
    }

  }
  return 0;
}