#include <iostream>
#include <vector>

using namespace std;

typedef uint64_t ui;

int main(){
  int t;
  cin>>t;
  while (t--){
    int n , k;
    cin>>n>>k;
     vector<int> v(n);
     for(int i = 0; i <n ; i++){
       cin>>v[i];
     } 

     ui pre = v[0], sum = 0;
     for(int i = 1; i < n; i++){
       long long int diff = ((100*v[i]) - (pre*k));
       if(diff  > 0){
         sum += diff;
         pre += diff;
       }
       pre += v[i];
     }
    cout<<sum<<"\n";
  }
  
  return 0;
}