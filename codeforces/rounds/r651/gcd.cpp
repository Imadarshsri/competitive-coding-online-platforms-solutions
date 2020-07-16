// --------------------<optimizations>--------------------\
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)\
#pragma GCC optimize("unroll-loops")
// -------------------</optimizations>--------------------

#include<bits/stdc++.h>
using namespace std;
//Macros
#define endl "\n"
#define pb push_back
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef uint64_t ui;
typedef vector<int> vi;
typedef vector<vi> vvi;

int maxGCD(int n){
  vi arr;
  for(int i=1;i<=n;i++){
    arr.pb(i);
  }
    int high = 0; 
    for (int i = 0; i < n; i++) 
        high = max(high, arr[i]); 
  
    int count[high + 1] = {0}; 
    for (int i = 0; i < n; i++) 
        count[arr[i]]++; 
  
    int counter = 0; 
  
    for (int i = high; i >= 1; i--){ 
        int j = i; 
       counter = 0;
        while (j <= high){ 
  
            if(count[j] >=2) 
               return j; 
  
           else if (count[j] == 1)          
                counter++;           
            j += i; 
  
            if (counter == 2)          
                return i; 
        } 
    } 
    return 1;
} 
void solve(){
  int n = 2;
  cin>>n;
  cout<<maxGCD(n)<<"\n";
}

int main(){
/*
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
*/
  // fastio

  int cases=1;
  //fastscan(cases);
  scanf("%d",&cases);
  while(cases--){
    solve();
  }
  return 0;
}