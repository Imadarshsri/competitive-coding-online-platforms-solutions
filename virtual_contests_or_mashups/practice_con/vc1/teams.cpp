#include<bits/stdc++.h>

using namespace std;
typedef uint64_t ui;

ui solve(){
  ui n =0, mx = 0;
  cin >> n;
  map<ui,ui> m;
  for(ui i = 0; i < n; i++){
    ui x = 0;
    cin >> x;
    m[x]++;
    mx = max(mx, m[x]);
  }

  ui a = m.size();
  return max(min(mx - 1, a), min(mx, a - 1));
}

int main(){
  int cases = 1;
  scanf("%d", &cases);
  while (cases--){
    cout << solve() << "\n";
  }
  return 0;
}