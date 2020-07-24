#include <iostream>
using namespace std;
int main(){
  int problems = 1;
  cin>>problems;
  int ans = 0;
  while(problems--){
    int x, y, z;
    cin>>x>>y>>z;
    if((x+y+z) > 1) ans++;
  }
  cout<<ans<<"\n";
}