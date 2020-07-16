#include<iostream> 
#include<string> 
using namespace std; 

int main(){ 
  
  int x=0,n=1; 
  cin>>n; 
  while(n--){ 
    string statement; 
    cin>>statement; 
    if(statement.substr(1,1) == "-") x--; 
    else if(statement.substr(1,1) == "+") x++; 
  } 
  cout<<x<<"\n"; 
  return 0; 
} 
