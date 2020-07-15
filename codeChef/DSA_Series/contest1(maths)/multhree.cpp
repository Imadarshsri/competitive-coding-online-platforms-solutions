#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    ll k=2,d0=1,d1=0;
    cin>>k>>d0>>d1;
    ll temp = (d0 + d1);
    ll sum = ((2*temp)%10) + ((4*temp)%10) + ((8*temp)%10) + (6*temp)%10;
    ll ans = temp;
    k-=2;
    if(k>0){
      ans+=(temp%10);
      k--;
    }
    ans += (k/4)*sum;
    k %= 4;
    int s =2;
    while(k--){
      ans+=(s*temp)%10;
      s = (s*2)%10;
    }
    if(ans%3!=0){
      cout<<"NO\n";
    }
    else
      cout<<"YES\n";
  }
  return 0;
}