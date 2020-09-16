#include<bits/stdc++.h>
using namespace std;
//Macros
#define fo(n) for(auto i =0;i<n;i++)
#define fn(x,n) for(;x<n;x++)

#define see(x) cout<<#x<<" = "<<(x)<<"\n"
#define look(v) cout<<#v<<" : "; for(auto x:v) cout<<x<<" "; cout<<endl

#define vi vector<int> 
#define vui vector<uint64_t> 
#define vvi vector<vector<int>>
#define mi map<int>

#define pb push_back
#define mp make_pair
#define ll long long
#define ui uint64_t
#define rem 1000000007

int main(){
    int l=1,r = 1000;
    while(l!=r){
      int mid = (r+l +1) /2;
      printf("%d\n",mid);
      fflush(stdout);
      char cmp[3];
      scanf("%s",cmp);
      if(strcmp(cmp,"<")==0){
        r = mid-1;
      }
      else  l = mid;
    }
    printf("! %d\n",l);
    fflush(stdout);
    return 0;
}