#include<bits/stdc++.h>

using namespace std;
#define N 1000000
typedef uint64_t ui;
vector<int> ans(N+5);
bool prime[N+5]; 
void calPrime(){
    memset(prime, true, sizeof(prime)); 
    prime[0] = false;
    prime[1] = false;
    for (int i=2; i*i<N+5; i++){ 
        if (prime[i] == true){ 
            for (int j=i*i; j<N+5; j += i) 
                prime[j] = false; 
        } 
    } 
}

void solve(){
  int n;
  cin>>n;
  cout<<ans[n]<<"\n";
}

int main(){
  int cases=1;
  scanf("%d",&cases);

  calPrime();
  int i = 2, cnt = 0;
  for(i = 2; i <= N; i++){
    if(prime[i-2] && prime[i])
      ans[i] = ans[i-1] + 1;
    else 
      ans[i] = ans[i-1];
  }
  while(cases--){
    solve();
  }
  return 0;
}