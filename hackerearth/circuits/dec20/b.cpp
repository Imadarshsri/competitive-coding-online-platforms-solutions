#include<iostream>
#include<vector>

using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define readSeq(v, n) for(int i = 0; i < n; i++) cin>>v[i];
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;

void solve(){
  int n;
  int cost01 = 0, cost10 = 0;
  uint64_t sum1 = 0, sum2 = 0;
  cin >> n >> cost01 >> cost10;
  // vector<int> v(n);
  int x = 0;
  for(int i = 0; i < n; i++){
    cin>>x;
    if((i&1) == 0){
      //Even index
      //Follow 01
      if(x!=0){
        sum1 += cost10;
        // cout<<"01-> X\n";
      }
      //Follow 10
      else if(x!=1){
        sum2 += cost01;
        // cout<<"10-> Y\n";
      }
    } 
    else{
      //odd index
      //Follow 01
      if(x!=1){
        sum1 += cost01;
        // cout<<"01-> Y\n";
      }
      //Follow 10
      else if(x!=0){
        sum2 += cost10;
        // cout<<"10-> X\n";
      }

    }
  }
  // cout<<sum1<<"--"<<sum2<<"\n";
  cout<<min(sum1,sum2)<<"\n";
}

int main(){
  //fastio

  int cases=1;
  //fastscan(cases);
  scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}