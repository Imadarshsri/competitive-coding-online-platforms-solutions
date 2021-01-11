#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef uint64_t ui;

int main(){
  int n, streetLength;
  cin >> n >> streetLength;
  vector <ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  
  sort(a.begin(), a.end());

  double max_dist = 0;
  for(int i = 1; i < n; i++){
    max_dist = max(max_dist, (a[i] - a[i - 1])/2.0);
  }
  cout<<max((a[0] - 0)*1.0, max(max_dist, (streetLength - a[n-1])*1.0));
}