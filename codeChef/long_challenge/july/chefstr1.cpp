#include <iostream>
using namespace std;
int main(){
  int cases = 1;
  scanf("%d", &cases);
  while(cases--){
    int n = 2,prev = 1;
    uint64_t stringsSkipped = 0;
    cin>>n;
    cin>>prev;n--;
    while(n--){
      int x;
      cin>>x;
      stringsSkipped += abs(prev - x) - 1;
      prev = x;
    }
    cout<<stringsSkipped<<"\n";
  }
  return 0;
}