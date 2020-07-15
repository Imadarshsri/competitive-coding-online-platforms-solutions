#include<stdio.h>
// using namespace std;
int main(){
  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    int n,max,tmp,ans=1;
    scanf("%d",&n);
    scanf("%d",&max);
    while(--n){
      scanf("%d",&tmp);
      if(max>=tmp){
        ans++;
        max = tmp;
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}