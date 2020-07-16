//Question::
// Chef has an integer N and he wants to generate a matrix M with N rows (numbered 1 through N) and N columns (numbered 1 through N). He thinks that M would be delicious if:

// Each element of this matrix is an integer between 1 and N2 inclusive.
// All the elements of the matrix are pairwise distinct.
// For each square submatrix containing cells in rows r through r+a and in columns c through c+a (inclusive) for some valid integers r, c and a≥0:
// Mr,c+Mr+a,c+a is even
// Mr,c+a+Mr+a,c is even
// Can you help Chef generate a delicious matrix? It can be proved that a solution always exists. If there are multiple solutions, you may find any one

// Input: 
// T
// N
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
#define mp make_pair
#define sz(x) int(x.size())
#define fn(x,n) for(; x < n; x++)
#define all(v) (v).begin(),(v).end()
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef uint64_t ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ui> vui;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef map<int,int> mi;
typedef set<int> si;

const ll mod = 1e9 + 7;
const ll INF = 1e18;

void solve(){
  int n=1;
  cin>>n;
  if(n==1){
    cout<<1<<"\n";
    return;
  }

  for(int i=1,j=0;i<n*n&&j<n;j++){
    for(int k=0;k<n;k++,i++){
      if(!(n&1)){
        if(!(j&1)) cout<<i<<" ";
        else if((j&1)&&!(k&1))
            cout<<(i+1)<<" ";
        else if((j&1)&&(k&1))
          cout<<(i-1)<<" ";
      }
      else
        cout<<i<<" ";
    }
    cout<<"\n";
  }
}
int main(){
  int cases=1;
  scanf("%d",&cases);
  while(cases--)
    solve();
  return 0;
}
