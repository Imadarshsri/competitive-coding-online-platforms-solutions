#include<bits/stdc++.h>
using namespace std;
//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl
#define lookPairs(v) cout<< #v << " : "; for(auto x : v) cout<< x.first << " "<<x.second<<"\n"

typedef long long ll;
typedef uint64_t ui;


int continuosCharCount(string str, int idx, int length){ 
   int cntt = 0;
   char c = str[idx];
   while(str[idx] == c && idx < length) {
      cntt++; idx++;
   }
   return cntt;
}
void solve(){
   string str, pattern, ans = "";
   cin>>str>>pattern;

   map <char,int> strCharCount, patternCharCount;
   for(auto x: str) strCharCount[x]++;
   for(auto x: pattern) patternCharCount[x]++;

   lookPairs(strCharCount);
   lookPairs(patternCharCount);

   //Subtracting char count of pattern from strCount to reserve this pattern characters
   for(auto x: patternCharCount){
      cout<<"IN subs Loop\n";
      if(strCharCount[x.first] == x.second){
         strCharCount.erase(x.first);
      }
      else{
         strCharCount[x.first] -= x.second;
      }
   }
   //If str == pattern 
   if(strCharCount.empty()) {
      cout<<pattern<<"\n";
      return;
   }
   lookPairs(strCharCount);
   // Initalizing begin pointer
   int patternPtr = 0;
   map<char,int> :: iterator i = strCharCount.begin(); 

   //ADD lexicographically smaller charactes first compared to first character of pattern

   while(i != strCharCount.end() && i->first < pattern[patternPtr]){
      cout<<"IN Loop\n";
      debug(i->first);
      ans += string(i->second, i->first);
      i = strCharCount.erase(i);
      cout<<"Charaters added -> ";
      debug(i->first);
      cout<<"1 Ans => ";
      debug(ans);
   }
   //Compare and add 
   if(i->first == pattern[patternPtr]){
      cout<<"equals char found\n";
      int sameCharAtBeginingOfPattern = continuosCharCount(pattern, 0, pattern.length());
      int noOfCharsToBeAdded = min(sameCharAtBeginingOfPattern, strCharCount[i->first] == -1 ? 0 : strCharCount[i->first]);

      char charToBeAdded = i->first;
      debug(noOfCharsToBeAdded);
      debug(charToBeAdded);
      ans += string(noOfCharsToBeAdded, i->first);
      patternPtr += (int)noOfCharsToBeAdded;   
      strCharCount[i->first] -= noOfCharsToBeAdded;
      debug(patternPtr);
      // if(strCharCount[i->first] <= 0) {
      //    i = strCharCount.erase(i);
         // cout<<"str k chars add huye hai\nDeleted";
      //    lookPairs(strCharCount);
      //    debug(i->first);
      //    ans += pattern.substr(patternPtr, pattern.length() - patternPtr + 1);
      //    strCharCount[charToBeAdded] += noOfCharsToBeAdded;
      //    i--;
         // cout<<"69XX Ans => ";
      //    debug(ans);
      //    lookPairs(strCharCount);
      //    while(i != strCharCount.end()){
            // cout<<"687IN Loop\n";
      //       debug(i->first);
      //       ans += string(i->second, i->first);
      //       i = strCharCount.erase(i);
            // cout<<"xxsd later Charaters added -> Deleted";
      //       lookPairs(strCharCount);
      //       debug(i->first);
      //    if(i == strCharCount.end()){
            // cout<<"checking out--";
      //       cout<<ans<<"\n"  ;
      return;
      //    }
      //    }
      //    if(i == strCharCount.end()){
            // cout<<"checking out--";
      //       cout<<ans<<"\n"  ;
      return;
      //    }
      // }
      debug(patternPtr);
      //At the end of Pattern
      if(patternPtr == pattern.length()){
         cout<<"Ended Pattern";
         debug(ans);
         strCharCount[charToBeAdded] += noOfCharsToBeAdded;
         // i--;
         while(i != strCharCount.end()){
            cout<<"IN Loop\n";
            debug(i->first);
            ans += string(i->second, i->first);
            i = strCharCount.erase(i);
            cout<<"later Charaters added -> ";
            debug(i->first);
            if(i == strCharCount.end()){
               cout<<"checking out--";
               cout<<ans<<"\n"  ;
               return;
            }
         }
         cout<<ans<<"\n";
         return;
      }
      if(i->first <= pattern[patternPtr]){
         //Add str characters first
         patternPtr = 0;
         ans += string(i->second, i->first);
         i = strCharCount.erase(i);
         cout<<"Deleted";
         lookPairs(strCharCount);
         debug(i->first);
         //Copy pattern
         ans += pattern; 
         if(i == strCharCount.end()){
            cout<<"checking out--";
            cout<<ans<<"\n"  ;
            return;
         }
         while(i != strCharCount.end()){
            cout<<"IN end Loop\n";
            debug(i->first);
            ans += string(i->second, i->first);
            i = strCharCount.erase(i);
            cout<<"xdsdsx later Charaters added -> ";
            cout<<"Deleted";
            lookPairs(strCharCount);
            debug(i->first);
            if(i == strCharCount.end()){
               cout<<"checking out--";
               cout<<ans<<"\n"  ;
               return;
            }
         }
      
      }
      else{
         ans += pattern.substr(patternPtr, pattern.length() - patternPtr + 1);
         strCharCount[charToBeAdded] += noOfCharsToBeAdded;
         i = strCharCount.begin();
         // i--;
         cout<<"3XX Ans => ";
         debug(ans);
         while(i != strCharCount.end()){
            cout<<"IN Loop\n";
            debug(i->first);
            ans += string(i->second, i->first);
            i = strCharCount.erase(i);
            cout<<"xx later Charaters added -> ";
            cout<<"Deleted";
            lookPairs(strCharCount);
            debug(i->first);
         }
      }
   if(i == strCharCount.end()){
      cout<<"checking out--";
      cout<<ans<<"\n"  ;
      return;
      }
   }
   else{
      ans += pattern; //.substr(patternPtr, pattern.length() - patternPtr + 1);
      cout<<"2 Adding substr Ans => ";
      debug(ans);
      while(i != strCharCount.end()){
         cout<<"IN Loop\n";
         debug(i->first);
         ans += string(i->second, i->first);
         i = strCharCount.erase(i);
         cout<<"later Charaters added -> ";
         debug(i->first);
         if(i == strCharCount.end()){
            cout<<"checking out--";
            cout<<ans<<"\n"  ;
            return;
         }
      }
      cout<<"4 Ans => ";
      debug(ans);
      cout<<ans<<"\n"  ;
      return;

      if(i == strCharCount.end()){
         cout<<"checking out--";
         cout<<ans<<"\n"  ;
         return;
      }
   }
   cout<<ans<<"\n";
   return;
}

int main(){
//   fastio
  int cases=1;

//   #ifndef ONLINE_JUDGE
//   freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);
//   #endif
   scanf("%d",&cases);
  while(cases--){
      // cout<<"main Loop\n";
    solve();
  }
  return 0;
}