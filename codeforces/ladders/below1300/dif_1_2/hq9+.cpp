#include <iostream>
#include <string>

using namespace std;
int main(){
  string a, b;
  cin>>a;
  for(auto x : a){
    if(x == 'H' || x == 'Q' || x == '9'){ 
      cout<<"YES\n";
      return 0;
    }
  }
  cout<<"NO\n";
  return 0;
}