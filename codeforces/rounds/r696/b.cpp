#include<bits/stdc++.h>
using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define readSeq(v, n) for(int i = 0; i < n; i++) cin>>v[i];
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl
#define N 100000
typedef uint64_t ui;
vector<int> primes;
void calPrime(){
    bool prime[N]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int i=2; i*i<N; i++){ 
        if (prime[i] == true){ 
            for (int j=i*i; j<N; j += i) 
                prime[j] = false; 
        } 
    } 
  
    for (int i=2; i<N; i++) 
       if (prime[i]) 
        primes.push_back(i);
}
void solve(){
  int d;
  cin>>d;
  ui div1 = d+1;
  div1 = *lower_bound(primes.begin(), primes.end(), div1);
  ui div2 =  *lower_bound(primes.begin(), primes.end(), div1 + d);
  cout<<div1*div2<<"\n";
}

int main(){
  // fastio

  int cases=1;
  scanf("%d",&cases);
  calPrime();
  while(cases--){
    solve();
  }
  return 0;
}