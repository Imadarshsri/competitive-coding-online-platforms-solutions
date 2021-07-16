#include<bits/stdc++.h>
using namespace std;

typedef uint64_t ui;

vector<int> primeBuckets(ui n){
   vector<int> bucket(4, 0);
   while(n>0) {
      int x = n % 10;
      n /= 10;
      switch(x) {
         case 2: bucket[0] = 1; break;
         case 3: bucket[1] = 1; break;
         case 5: bucket[2] = 1; break;
         case 7: bucket[3] = 1; break;
      }
   }
   return bucket;
}
ui ncr(int n, int r) {
    ui p = 1, k = 1;

    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
 
            n--;
            r--;
        }
    }
 
    else
        p = 1;
 
   return p;
}

ui solve(){
  int n;
  cin>>n;
//   map<int, int> mp;
  vector<ui> dia(n), mp(4);
  for(int i = 0; i < n; i++) {
     cin >> dia[i];
     auto v = primeBuckets(dia[i]);
     mp[0] += v[0];
     mp[1] += v[1];
     mp[2] += v[2];
     mp[3] += v[3];
  }
   ui ans = 0;
   for(auto x: mp) {
      // cout<<x.first<<": "<<x.second<<endl;
      if(x >= 3) {
         ans += ncr(x, 3);
      }
   }
   return ans;
}

int main(){
  iski jagah cout<<solve();  ye hoga cout<<solve()<<"\n";
  return 0;
}