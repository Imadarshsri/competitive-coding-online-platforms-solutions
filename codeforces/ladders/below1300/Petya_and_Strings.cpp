#include <iostream>
#include <string>

using namespace std;
int main(){
  string a, b;
  cin>>a>>b;
  for(int i = 0;i < a.length();i++){
    if(a[i] >= 'A' && a[i] <= 'Z'){
      a[i] = (a[i] - 'A') + 'a';
    }
    if(b[i] >= 'A' && b[i] <= 'Z'){
      b[i] = (b[i] - 'A') + 'a';
    }
  }
  for(int i = 0; i < a.length() ; i++){
    if(a[i] > b[i]){
      cout<<"1\n";
      return 0;
    }
    else if(a[i] < b[i]){
      cout<<"-1\n";
      return 0;
  
    }
  }
  cout<<"0\n";
  return 0;
}