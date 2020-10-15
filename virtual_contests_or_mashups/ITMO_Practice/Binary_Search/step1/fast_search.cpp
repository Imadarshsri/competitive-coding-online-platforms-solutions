#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int floor(const vector<int>& v, int x){
  int l = 0, r = v.size() - 1, ans = 0;
  while(l <= r){
    int mid = l + (r - l)/2;
    if(v[mid] <= x){
      ans = mid;
      l = mid + 1;
    }
    else if(v[mid] > x) r = mid - 1;
  }
  return r == -1 ? r : ans;
}

int ceil(const vector<int>& v,const int x){
  int n = v.size();
  int l = 0, r = n - 1, ans = 0;
  while(l <= r){
    int mid = l + (r - l)/2;
    if(v[mid] >= x){
      ans = mid;
      r = mid - 1;
    }
    else if(v[mid] < x) l = mid + 1;
  }
  return l == n ? l : ans;
}

int main(){
  int n, q;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  
  cin >> q;
  while(q--){
    int l, r;
    cin >> l >> r;
    cout << floor(v, r) - ceil(v, l) + 1<< "\n";
  }
  return 0;
}