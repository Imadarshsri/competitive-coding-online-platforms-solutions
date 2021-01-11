// Merge two sorted array w/o using extraspace

#include <iostream>
#include <vector>

using namespace std;
//Macros
#define endl "\n"
#define fn(x, n) for (; x < n; x++)
#define fo(n) for (auto i = 0; i < n; i++)
#define debug(x) cout << #x << " = " << (x) << "\n"
#define readSeq(v, n)         \
  for (int i = 0; i < n; i++) \
    cin >> v[i];
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define look(v)        \
  cout << #v << " : "; \
  for (auto x : v)     \
    cout << x << " ";  \
  cout << endl

typedef uint64_t ui;

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  fo(n) cin >> a[i];
  fo(m) cin >> b[i];

  fo(n) cout << a[i] << " ";
  fo(m) cout << b[i] << " ";
}

int main()
{
  //fastio

  int cases = 1;
  //fastscan(cases);
  scanf("%d", &cases);
  while (cases--)
  {
    solve();
  }
  return 0;
}