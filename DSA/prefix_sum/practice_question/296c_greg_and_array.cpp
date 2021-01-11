#include<bits/stdc++.h>
// #include<vector>
// #include<map>

using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define readSeq(v, n) for(int i = 0; i < n; i++) cin>>v[i];
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;
typedef long long ll;

#define N 100002
/*
296c
// Greg has an array a = a 1, a 2, ..., a n and m operations. Each operation looks as: l i, r i, d i, (1 ≤ l i ≤ r i ≤ n). To apply operation i to the array means to increase all array elements with numbers l i, l i + 1, ..., r i by value d i.

Greg wrote down k queries on a piece of paper. Each query has the following form: x i, y i, (1 ≤ x i ≤ y i ≤ m). That means that one should apply operations with numbers x i, x i + 1, ..., y i to the array.

Now Greg is wondering, what the array a will be after all the queries are executed. Help Greg.
Input
The first line contains integers n, m, k (1 ≤ n, m, k ≤ 105). The second line contains n integers: a 1, a 2, ..., a n (0 ≤ a i ≤ 105) — the initial array.

Next m lines contain operations, the operation number i is written as three integers: l i, r i, d i, (1 ≤ l i ≤ r i ≤ n), (0 ≤ d i ≤ 105).

Next k lines contain the queries, the query number i is written as two integers: x i, y i, (1 ≤ x i ≤ y i ≤ m).

The numbers in the lines are separated by single spaces.

Output
On a single line print n integers a 1, a 2, ..., a n — the array after executing all the queries. Separate the printed numbers by spaces.

Please, do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams of the %I64d specifier.

Examples
Input
3 3 3
1 2 3
1 2 1
1 3 2
2 3 4
1 2
1 3
2 3
Output
9 18 17
*/
class op{
  public : 
    int l;
    int r;
    int d;
    ll cnt;
    op(int x, int y, int z);
};
op::op(int x, int y, int z){
  l = x;
  r = y;
  d = z;
  cnt = 0;
}
void solve(){
  int n = 1, ops = 1, ques = 1;

  map<int,class op* > operations;
  cin>>n>>ops>>ques;
  // op x = op(2, 5, 3);
  // cout<<" ->  ("<<x.l<<", "<<x.r<<", "<<x.d<<")\n";
  ll arr[n] = {0};
  ll arr2[n + 2] = {0};
  // look(arr2);
  fo(n) cin>>arr[i];
  // look(arr);
  fo(ops){
    int x = 0,y = 0,z = 0;
    cin>>x>>y>>z;
    operations[i + 1] = new op(x,y,z);
  }
  operations[ops + 1] = new op(-1,-1, 0);
  // for(auto x : operations){
  //   cout<<x.first<<" ->  ("<<x.second->l<<", "<<x.second->r<<", "<<x.second->d<<", cnt : "<<x.second->cnt<<")\n";
  // }
  for(int j = 0; j < ques; j++){
    int a = 0, b = 0;
    cin>>a>>b;
    operations[a]->cnt++;
    operations[b + 1]->cnt--;
  }
  // for(auto x : operations){
  //   cout<<x.first<<" ->  ("<<x.second->l<<", "<<x.second->r<<", "<<x.second->d<<", cnt : "<<x.second->cnt<<")\n";
  // }
  for(int i = 2; i <= ops; i++){
    operations[i]->cnt += operations[i - 1]->cnt;
  }
  // for(auto x : operations){
  //   cout<<x.first<<" ->  ("<<x.second->l<<", "<<x.second->r<<", "<<x.second->d<<", cnt : "<<x.second->cnt<<")\n";
  // }
   for(int i = 1; i <= ops; i++){
      // cout<<i<<"-x-";
      // op * oprt = operations[i];
      arr2[operations[i]->l] += (operations[i]->d * operations[i]->cnt);
      arr2[(operations[i]->r) + 1] -= (operations[i]->d * operations[i]->cnt);
  }
  // for(auto x : operations){
  //   cout<<x.first<<" ->  ("<<x.second->l<<", "<<x.second->r<<", "<<x.second->d<<", cnt : "<<x.second->cnt<<")\n";
  // }
  for(int i = 1; i <= n; i++){
    arr2[i] += arr2[i - 1];
  }
  // look(arr); 
  // look(arr2);
  for(int i = 0; i < n ; i++){
    cout<<(ll)arr[i] + (ll)arr2[i + 1]<<" ";
  }
  cout<<"\n";
}

int main(){
  fastio

  int cases = 1;
  //fastscan(cases);
  // scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}