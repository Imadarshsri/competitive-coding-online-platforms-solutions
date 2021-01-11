#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int> &v,const int x){
  int l = 0, r = v.size() - 1;
  while(l <= r){
    int mid = l + (r - l)/2;
    if(v[mid] == x) return mid;
    else if(mid > l && v[mid - 1] == x) return mid - 1;
    else if(mid < r && v[mid + 1] == x) return mid + 1;
    else if(v[mid] > x) r = mid - 2;
    else l = mid + 2;
  }
  return -1;
}
int main(){
  int n = 1, x = 0;
  cin>>n;
  vector<int> v(n);
  for(int i = 0;i < n; i++) cin>>v[i];
  cin>>x;
  cout<<solve(v,x);
  return 0;
}