//Problem Statement
///A - Kuriyama Mirai's Stones

/*Kuriyama Mirai has killed many monsters and got many (namely n) stones. She numbers the stones from 1 to n. The cost of the i-th stone is v i. Kuriyama Mirai wants to know something about these stones so she will ask you two kinds of questions:

She will tell you two numbers, l and r (1 ≤ l ≤ r ≤ n), and you should tell her .
Let u i be the cost of the i-th cheapest stone (the cost that will be on the i-th place if we arrange all the stone costs in non-decreasing order). This time she will tell you two numbers, l and r (1 ≤ l ≤ r ≤ n), and you should tell her .
For every question you should give the correct answer, or Kuriyama Mirai will say "fuyukai desu" and then become unhappy.

Input
The first line contains an integer n (1 ≤ n ≤ 105). The second line contains n integers: v 1, v 2, ..., v n (1 ≤ v i ≤ 109) — costs of the stones.

The third line contains an integer m (1 ≤ m ≤ 105) — the number of Kuriyama Mirai's questions. Then follow m lines, each line contains three integers type, l and r (1 ≤ l ≤ r ≤ n; 1 ≤ type ≤ 2), describing a question. If type equal to 1, then you should output the answer for the first question, else you should output the answer for the second one.

Output
Print m lines. Each line must contain an integer — the answer to Kuriyama Mirai's question. Print the answers to the questions in the order of input.
*/

// #include <iostream>

// #include <vector>
// #include <tuple>
// #include <algorithm>
// #include <map>
// #include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
typedef uint64_t ui;

void solve(){
   fastio
   int n = 1, queries = 1;
   map < tuple < int, int, int >, ui > hm;
   cin>>n;
   vector<ui> v1(n);
   fo(n) cin>>v1[i];
   vector<ui> v2(v1), s1(n), s2(n);
   sort(v2.begin(), v2.end());
   s1[0] = v1[0];
   s2[0] = v2[0];
   
   for(int i = 1; i < n; i++){
      s1[i] = s1[i - 1] + v1[i];
      s2[i] = s2[i - 1] + v2[i];
   }
   // look(v1);
   // look(s1);
   // look(v2);
   // look(s2);

   cin>>queries;
   while(queries--){
      int l ,r, type;
      ui ans = 0;
      cin>>type>>l>>r;
      l--;r--;
      map<tuple<int,int, int>, ui>:: iterator p;
      if((p = hm.find(make_tuple(type,l,r))) != hm.end()){
         cout<<p->second;
      }
      else{
         switch (type){
            case 1:
               hm[make_tuple(type, l ,r)] = (ui)((ui)s1[r] - (ui)s1[l] + (ui)v1[l]);
               cout<<s1[r] - s1[l] + v1[l];
               break;

            case 2:
               hm[make_tuple(type, l ,r)] = (ui)((ui)s2[r] - (ui)s2[l] + (ui)v2[l]);
               cout<<s2[r] - s2[l] + v2[l];
               break;

            default:
               break;
         }
      }
      cout<<endl;  
   }
}

int main(){
  //fastio

   // freopen("input.txt", "r", stdin);
   // freopen("outut.txt", "w", stdout);
  int cases=1;
  //fastscan(cases);
  while(cases--){
    solve();
  }
  return 0;
}