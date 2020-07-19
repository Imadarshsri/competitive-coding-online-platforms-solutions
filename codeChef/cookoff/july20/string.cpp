#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
   int cases = 1;
   cin>>cases;
   while (cases--){
      int n;
      map<int,int> charCount;
      cin>>n;
      string s;
      cin>>s;
      int flag = 0;
      for(int i =0;i < n; i++){
         charCount[s[i]]++;
      }
      for(auto x : charCount){
         if(x.second & 1){
            cout<<"NO\n";
            flag = 1;
            break;
         }
      }
      if(flag == 0) cout<<"YES\n";
   }
   return 0;
}