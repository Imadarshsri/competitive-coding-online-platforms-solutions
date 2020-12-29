#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
  int t = 1;
  cin >> t;
  while(t--){
    int n = 0;
    cin >> n;
    map <int, pair<int,int>> m;
    int x = 0;
    for(int i = 0; i < n; i++){
      cin>>x;
      if(m.find(x) == m.end()){
        m[x] = make_pair(i, i);
      }
      else{
        m[x].second = i;
      }
    }
    
    uint64_t sum = 0;
    for(auto x : m){
      sum += x.second.second - x.second.first;
    }
    cout<<sum<<"\n";
  }
  return 0;
}