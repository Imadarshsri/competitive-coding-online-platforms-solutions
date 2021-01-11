#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef uint64_t ui;

int main(){
  int n,m;
  cin >> n;
  vector <ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  vector <ll> b(m);
  for(int i = 0; i < m; i++) cin >> b[i];
  
  sort(a.begin(), a.end());
  //Modified ceil Code
  for(auto x : b){
    int ans = -1;
    int l = 0, r = n - 1;
    while (l <= r){
      int mid = l + (r - l)/2;
      if(a[mid] <= x)
        l = mid + 1;
      else{
        ans = mid;
        r = mid - 1;  
      }
    }
    cout << l << " ";
  }
}