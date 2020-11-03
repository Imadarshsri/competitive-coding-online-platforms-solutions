#include <iostream>
using namespace std;
typedef uint64_t ui;
typedef long long int ll;
ui binExpo(ui x, ui y, ui n){
   int ans = 1;

   while(y){
      if(y&1) ans *= x;

      ans = 2*
   }
   return ans;
}
int main(){
   ui t = 0, faltu = 0;
   cin >> t;
   while(t--){
      ui x = 1, y = 1, n = 1;
      cin >> x >> y >> n;
      cout << binExpo(x,y,n);
   }
   cin >> faltu;
}
