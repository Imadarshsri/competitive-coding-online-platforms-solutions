#include <iostream>
#include <cinttypes>
#include <vector>
using namespace std;
typedef uint64_t ui;
typedef long long ll;

#define N 1000002


int main(){
  ui n = 1;
  vector <ui> p(N,1), q(N,1);
  scanf("%" SCNu64, &n);

  p[0] = p[1] = 0;
  q[0] = q[1] = 0;
  for(ui i = 2; i < N; i++){
    if(p[i] == 1){
      for(ui j = i*i; j < N; j += i){
        p[j] = 0; 
        q[j] = 0;
      }
    }
  }

   for(ui i = 1; i < N; i++){
    if(p[i] == 1){
      ui x = i, y = 0;
      while(x){
        y += x%10;
        x /= 10;
      }
      p[i] = q[y];
    }
    p[i] += p[i - 1];
  }

  while(n--){
    ui l = 1, r = 1;
    scanf("%" SCNu64 "%" SCNu64, &l, &r);
    printf("%+" PRIu64 "\n", (ui)p[r] - (ui)p[l - 1]);
  }
  return 0;  
}