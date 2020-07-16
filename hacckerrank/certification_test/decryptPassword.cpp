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

string decryptPassword(string s) {
    if(s.length() == 0) return "";
    stack<char> numSt;
    string ans = "";
    int j = 0;
    while(s[j] > '0' && s[j] <= '9' && j< s.length()){
      numSt.push(s[j]);
      // cout<<"num pushed "<<s[j];
      j++;
    }
    for(int i = j; i < s.length() ;i++){
        if(s[i] == '0'){
          if(!numSt.empty()){
            ans+=numSt.top();
            numSt.pop();
          }
          // cout<<"num "; debug(ans);
        }
        else if(s[i] >= 'A' && s[i] < 'Z'){

            if((i+2)<s.length() && s[i+2] == '*'){
                
              ans += s[i + 1];
              ans += s[i];
              i += 2;
              // cout<<"big small -- "; debug(ans);
            }
            else{
                ans += s[i];
                // cout<<"big only "; debug(ans);
            }
        }
        else{
          ans += s[i];
        }
    }
    return ans;
}
int main(){
/*
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
*/
  //fastio

  int cases=1;
  //fastscan(cases);
  // scanf("%d",&cases);
  while(cases--){
    string s;
    cin>>s;
    cout<<decryptPassword(s);
  }
  return 0;
}