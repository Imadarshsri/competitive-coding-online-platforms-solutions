#include <iostream>
#include <vector>

using namespace std;

string bs(const vector<int>& v, int x){
  int l = 0, r = v.size() - 1;
  while(l <= r){
    int mid = l + (r - l)/2;
    if(v[mid] == x) return "YES";
    else if(v[mid] > x) r = mid - 1;
    else l = mid + 1;
  }
  return "NO";
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