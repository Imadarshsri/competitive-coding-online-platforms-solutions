#include <iostream>
#include <vector>

using namespace std;

int main(){
   // freopen("input.txt","r",stdin); 
   // freopen("output.txt","w",stdout);
   int n = 1, m = 1;
   cin>>n>>m;
   int maxRight = 0, minWrong = 101;
   vector<int> right(n), wrong(m);
   for(int i = 0; i < n; i++){
      cin>>right[i];
      maxRight = max(right[i], maxRight);
   }
   for(int i = 0; i < m; i++){
      int x = 0;
      cin>>x;
      minWrong = min(x, minWrong);
   }
   int flag = 0;
   for(int i = maxRight; i < minWrong; i++){
      for(auto x : right){
         if(2*x <= i){
            cout<<i;
            flag = 1;
         }
         if(flag == 1) return 0;
      }
      if(flag == 1) return 0;
   }
   cout<<"-1\n";
   return 0;
}