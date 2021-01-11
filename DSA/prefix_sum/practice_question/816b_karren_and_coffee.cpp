#include<iostream>
#include<vector>

using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define readSeq(v, n) for(int i = 0; i < n; i++) cin>>v[i];
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl
#define N 200002
typedef uint64_t ui;

void solve(){

}

int main(){
  //fastio

  ui n = N, k = 1, queries = 1;
  ui arr[N] = {0};// arr[N] = {0};
  // cout<<arr[N-1];
  cin>>n>>k>>queries;
  // cout<<n<<" asd---"<<k<<"---"<<queries<<"\n";
  while(n--){
    int l = 0, r = 0;
    cin>>l>>r;
    arr[l] += 1;
    arr[r + 1] -= 1;
  }
  for(int i = 1; i < N; i++){
    arr[i] += arr[i - 1];
  }
  
  // for(int i = 1; i < 25; i++){
  //   cout<<arr[i]<<" ";
  // }
  for(int i = 1; i < N; i++){
    arr[i] = arr[i - 1] + (arr[i] >= k ? 1 : 0);
  }
  // cout<<"\n";
  // for(int i = 1; i < 25; i++){
  //   cout<<arr[i]<<" ";
  // }
  while(queries--){
    int a = 0, b = 0;
    cin>>a>>b;
    cout<<arr[b] - arr[a - 1]<<"\n";
  }
  return 0;
}