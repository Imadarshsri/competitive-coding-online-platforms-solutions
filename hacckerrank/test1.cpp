#include <bits/stdc++.h>
using namespace std;
string check(string str){
  int len = str.length();
  int x=0,y;
  len%2==0 ? y = len/2 : y = len/2+1;
  int count=0;
  map<char,int>m1,m2;
  while(x<len/2 && y<len){
    m1[str[x]]++;
    m2[str[y]]++;
    x++;y++;
  }
  for(auto c : str){
    if(m1[c] != m2[c]) return "NO";
  }
  return "YES";
}
int main(){
  int testcases;
  cin>>testcases;
  while(testcases-->0){
    string str;
    cin>>str;
    cout<<check(str)<<"\n";
  }
  return 0;
}