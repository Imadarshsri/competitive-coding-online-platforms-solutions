#include <iostream>
#include <vector> 
#include<map>
#include<algorithm>

using namespace std;
int main(){
  int n,m;
  map<int,int> vasya,petya;
  uint64_t vasyaOperation =0, petyaOperation = 0;
  vector<int> an;
  cin>>n;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    an.push_back(x);
  }
  cin>>m;
  for(int i = 0, k = n-1;i<=n/2 && (k>=n/2);i++,k--){
    vasya[an[i]] = i + 1;
    petya[an[i]] = n - i;
    petya[an[k]] = n - k;
    vasya[an[k]] = k + 1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
  }
  for(int j=0;j<m;j++){
    int x;
    cin>>x;
    vasyaOperation += vasya[x];
    petyaOperation += petya[x];
  }
  cout<<vasyaOperation<<" "<< petyaOperation<<"\n";
  vasya.clear();petya.clear();
  return 0;
}