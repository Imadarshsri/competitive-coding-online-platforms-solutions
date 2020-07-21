#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int main(){
   int n;
   cin>>n;
   map<int,int> m;
   vector<int> v;

   for(int i =0; i< n; i++){
      int x;
      cin>>x;
      v.push_back(x);
      m[x]++;
   }
   if(m[0] == 0) cout<<"-1\n";
   else if(m[5] < 9){
      cout<<"0\n";
   }
   else{
      m[5] -= m[5]%9;
      for(int i = 0; i<m[5]; i++){
         cout<<"5";
      }
      for(int i = 0; i<m[0]; i++){
         cout<<"0";
      }
   }
   return 0;
}