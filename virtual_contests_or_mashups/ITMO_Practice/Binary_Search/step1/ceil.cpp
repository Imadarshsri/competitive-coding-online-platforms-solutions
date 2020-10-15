#include <iostream>
#include <vector>

using namespace std;

int bs(const vector<int>& v,const int x){
  int n = v.size();
  int l = 0, r = n - 1, ans = 0;
  while(l <= r){
    int mid = l + (r - l)/2;
    if(v[mid] >= x){
      ans = mid + 1;
      r = mid - 1;
    }
    else if(v[mid] < x) l = mid + 1;
  }
  return l == n ? n + 1 : ans;
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