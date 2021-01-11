#include<iostream>

typedef long long ll;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int main(){
  ll a,b;
  std::cin>>a>>b;
  std::cout<<binpow(a,b)- binpow(b,a);
  return 0;
}