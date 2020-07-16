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
#define sz(x) int(x.size()),
#define fn(x,n) for(; x < n; x++)
#define all(v) (v).begin(),(v).end()
#define fo(n) for(auto i = 0; i < n; i++)
#define see(x) cout<< #x << " = " << (x) << "\n"
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

void fastscan(int &number){ 
  //variable to indicate sign of input number 
  bool negative = false; 
  register int c; 
  number = 0; 
  // extract current character from buffer 
  c = getchar(); 
  if (c == '-'){ 
    // number is negative 
    negative = true; 
    // extract the next character from the buffer 
    c = getchar(); 
  } 
  // Keep on extracting characters if they are integers 
  // i.e ASCII Value lies from '0'(48) to '9' (57) 
  for (; (c > 47 && c < 58); c = getchar()) 
    number = number *10 + c - 48; 
  // if scanned input has a negative sign, negate the 
  // value of the input number 
  if (negative) 
    number *= -1; 
} 

int main(){
  
  int cases=1;
  scanf("%d",&cases);
  while(cases--){
    int n,k;
    cin>>n>>k;
    ui ans=0,x=0;
    fo(n){
      cin>>x;
      ans+=x>k?(x-k):0;
    }
    cout<<ans<<endl;
  }
  return 0;
}