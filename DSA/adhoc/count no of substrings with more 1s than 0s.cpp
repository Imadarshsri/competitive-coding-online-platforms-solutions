#include<bits/stdc++.h>
using namespace std;

int solve(string s){
  int cnt = 0;
  int n = s.length();
  pair<int,int> m[n+1];
  m[0] = {0,0};
  int o = 0, z = 0;
  for(int i = 0; i < n; i++){
      if(s[i] == '0')
         z++;
      else
         o++;

      m[i+1] = {z,o};
  }   

  for(int len = 1; len <= n; len++){
     for(int i = len; i <= n; i++){
        if((m[i].first - m[i-len].first) < (m[i].second - m[i-len].second)) {
           cnt++;
        }
     }
  }
  return cnt;
}
int solve(string &s){
   int n = s.length();
   int ans = 0;

   if(n == 1)
      return (s[0] == '1');
   
   if(n == 2) {
      if ((s[0] == '1' && s[0] == s[1]))
         ans = 3;
      else 
         ans = (s[1] ^ s[0]);

      return ans;
   }

   if (s[n-1] == '1')
      ans += n;

   s.pop_back();
   ans += solve(s);
   
   return ans;
}
int main(){
   string str;
   cin >> str;
   cout<<solve(str); 
   return 0;
}