#include<bits/stdc++.h>
using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define readSeq(v, n) for(int i = 0; i < n; i++) cin>>v[i];
#define fastio ios_base::sync_with_stdio(false);cin.tie(NUui);

#define N 100003

typedef uint64_t ui;
unordered_map<ui,ui> m;
ui pw(ui x, ui y) { 
  ui res = 1;
  x = x % N; 
  if (x == 0) return 0;

	while (y > 0){ 
		if (y & 1) 
			res = (res*x)%N; 

		y = y>>1;
		x = (x*x)%N;
	} 
	return res;
}


ui pwSum(ui x) { 
  if(x <= 1)
    return 1;
  ui ans = 0;
  // if(!m.empty() && m.find(x) != m.end()) return m[x];
 while(x >= 1){
    auto a = (ui)pw((x)%N,x)%N;
  cout<<"\n"<<x<<" -> got A "<<a;
  auto b = (ui)pw((x-1)%N, x -1 );
  cout<<"\n"<<x<<" -> got B "<<b;

  if(x%2 == 0)
    ans +=  (ui)(N + b - a)%N;
  else
    ans += (ui)(N + a - b)%N;

    x-=2;
 }
 return ans;
}


int main(){

  int cases=1;
  scanf("%d",&cases);

  // for(ui i = 0; i<= N; i++){
  //   // 
  // }
  // for(ui i = 100000; i <= 1000000000000000000; i*=10) cout<<i<<" -> "<<pwSum(i)<<"\n";//cout<<i<<" -> "<<pw(i,i)<<"\n";
  while(cases--){
    ui n;
    cin>>n;
    cout<<pwSum(n)<<"\n";
  }
  return 0;
}