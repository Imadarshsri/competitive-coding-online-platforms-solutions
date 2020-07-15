#include<iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef uint64_t ui;
// Function to find the (n-2)C3
ui C(int n) { 
  return ((n*(n-1)*(n-2))/6);
} 
void solve(){
    int n,b1,b2;
    cin>>n>>b1>>b2;
    cout<<C(n-2)<<"\n";
}


int main(){
  fastio
  int cases=1;
  cin>>cases;
  while(cases--){
    solve();
  }
  return 0;
}