#include <iostream>
using namespace std;

void toh(int n, char from, char to, char aux){
  if(n==1){
     cout<<"Move "<<n<<"th disk from "<<from<<" to "<<to<<endl;
     return;
  }
  toh(n-1,from,aux,to);
  cout<<"Move "<<n<<"th disk from "<<from<<" to "<<to<<endl;
  toh(n-1,aux,to,from);
}

int main(){
  int n;
  cin>>n;
  toh(n,'A','C','B');
  return 0;
}