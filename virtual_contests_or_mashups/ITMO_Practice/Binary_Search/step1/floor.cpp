#include <iostream>
#include <vector>

using namespace std;

int bs(const vector<int>& v, int x){
  int l = 0, r = v.size() - 1, ans = 0;
  while(l <= r){
    int mid = l + (r - l)/2;
    if(v[mid] <= x){
      ans = mid + 1;
      l = mid + 1;
    }
    else if(v[mid] > x) r = mid - 1;
  }
  return r == -1 ? 0 : ans;
}

int main(){
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  while(q--){
    int x;
    cin >> x;
    cout << bs(v, x) << "\n";
  }
  return 0;
}