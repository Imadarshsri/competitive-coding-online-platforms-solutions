// Given a string s, print all its substring
#include <iostream>
#include <string>
using namespace std;

void solve(string s){
   int n = s.length();
   for(int i = 0; i < n; i++){
      for(int j = i; j < n; j++){
         cout<< s.substr(i, j - i + 1)<<", ";
      }
   }
}
int main(){
   string s;
   cin>>s;
   solve(s);
}