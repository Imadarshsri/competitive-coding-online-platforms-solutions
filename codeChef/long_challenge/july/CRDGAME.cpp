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
#define fo(n) for(auto i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int digits (int n){
  int sum = 0;
  while(n){
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main(){
  //fastio
  map<int,int> m;
  fo(9){
    m[i+1] = i+1;
  }
  int cases=1;
  scanf("%d",&cases);
  // debug(cases);
  while(cases--){
    int n; uint64_t chef = 0, morty = 0;
    cin>>n;
    while(n--){
      // debug(n);
      int a,b;
      cin>>a>>b;
      // debug(a); debug(b);
      if(a == b){
        chef++; morty++;
        // cout<<"a == b\n";
      }
      else if(a < 10 && (b % 10) > a){
        // cout<<"a < 10\n";
        morty++;
      }
      else if( b < 10 && (a % 10) > b){
        // cout<<"b < 10\n";
        chef++;
      }
      else{
        int Na = 0 , Nb = 0;
        if(m.find(a) != m.end()){
          // cout<<"a in Map\n";
          Na = m[a];
        }
        else{
          Na = digits(a);
          m[a] = Na;
        // cout<<"Na calcuated\n";
        }
        if(m.find(b) != m.end()){
        // cout<<"b in Map\n";

          Nb = m[b];
        }
        else{
          Nb = digits(b);
          m[b] = Nb;
        // cout<<"Nb calcuated\n";
        }
        if( Na == Nb ){
        // cout<<"Na == Nb\n";
          chef++;morty++;
        }
        else{
          Na > Nb ? chef++ : morty++;
        // cout<<"Na & Nb not equal\n";
        }
      }
      // debug(chef); debug(morty);
    } 
    if(chef == morty) cout<<"2 "<<chef<<"\n";
    else{
      chef > morty ? cout<<"0 "<<chef<<"\n" : cout<<"1 "<<morty<<"\n";
    }
  }
  return 0;
}