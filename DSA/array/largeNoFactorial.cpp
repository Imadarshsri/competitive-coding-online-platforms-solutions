#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define readSeq(v, n) for(int i = 0; i < n; i++) cin>>v[i];
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;

string mul(int num, string fact){
  int n = fact.length();
  int carry = 0;
  for(int i = n-1; i >= 0; i--){
      int digit = fact[i] - '0';
      int res = (digit*num) + carry;
      fact[i] = (char)((res%10) + '0');
      carry = res/10;
  }
  string s = "";
  while(carry>0){
    s = (char)((carry%10) + '0') + s;
    carry/=10;
  }
  
  fact = s + fact;
  return fact;
}

/// Using Logarithm Identity: https://www.geeksforgeeks.org/factorial-of-large-numbers-using-logarithmic-identity/
/// T(n): O(2n) where n = Largest number in input OR largest no.
// int main(){
//     int N = 15;
//     vector<long double> exps(N);
//     vector<string> facts(N);
//     exps[0] = 0;
//     exps[1] = 0;
//     for(int i = 2; i < N; i++){
//         exps[i] = exps[i-1] + log(i);
//     }
//     for(int i = 0; i < N; i++){
//         facts[i] = to_string(round(exp(exps[i])));
//     }
//     // look(facts);
//     int cases=1;
//     scanf("%d",&cases);
//     while(cases--){
//         int n;
//         cin>>n;
//         cout<<facts[n]<<"\n";
//     }
//     return 0;
// }

/// Using Simple Maths
/// T(n) : O(n*k), where n = no. of inputs, k = max no. of digits of largest number
int main(){
    int N = 1005;
    vector<string> facts(N);
    facts[0] = "1";
    facts[1] = "1";
    facts[2] = "2"; 
    for(int i = 3; i< N; i++){
        facts[i] = mul(i,facts[i-1]);
    }   
  int cases=1;
  scanf("%d",&cases);
  while(cases--){
      int n;
      cin>>n;
      cout<<facts[n]<<"\n";
  }
  return 0;
}

