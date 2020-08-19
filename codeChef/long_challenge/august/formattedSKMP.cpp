#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

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

   //Subtracting char count of pattern from strCount to reserve this pattern characters
   for(auto x: patternCharCount){
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
   
   int patternPtr = 0;
   map<char,int> :: iterator i = strCharCount.begin(); 
 
   //ADD lexicographically smaller characters first compared to first character of pattern
   while(i != strCharCount.end() && i->first < pattern[patternPtr]){
      ans += string(i->second, i->first);
      i = strCharCount.erase(i);
   }

   //Compare and add 
   if(i != strCharCount.end() && i->first == pattern[patternPtr]){
      int sameCharAtBeginingOfPattern = continuosCharCount(pattern, 0, pattern.length());
      int noOfCharsToBeAdded = min(sameCharAtBeginingOfPattern, strCharCount[i->first]);

      char charToBeAdded = i->first;
      ans += string(noOfCharsToBeAdded, i->first);
      patternPtr += (int)noOfCharsToBeAdded;   
      strCharCount[i->first] -= noOfCharsToBeAdded;
      //Adding str characters first
      if(i != strCharCount.end() && i->first <= pattern[patternPtr]){
         //Add str characters first
         patternPtr = 0;
         ans += string(i->second, i->first);
         i = strCharCount.erase(i);
         //Adding Pattern
         ans += pattern; 
         if(i == strCharCount.end()){
            cout<<ans<<"\n";
            return;
         }
         //Adding end characters of str
         while(i != strCharCount.end()){
            ans += string(i->second, i->first);
            i = strCharCount.erase(i);
            if(i == strCharCount.end()){
               cout<<ans<<"\n";
               return;
            }
         }
      
      }
      else{ 
         //Adding patterns Characters First
         ans += pattern.substr(patternPtr, pattern.length() - patternPtr + 1);
         strCharCount[charToBeAdded] += noOfCharsToBeAdded;
         //Adding end characters of str
         while(i != strCharCount.end()){
            ans += string(i->second, i->first);
            i = strCharCount.erase(i);
            }
      }
      if(i == strCharCount.end()){
         cout<<ans<<"\n";
         return;
      }
   }
   else{
      //Adding patterns Characters First
      ans += pattern; 
      //Adding end characters of str
      while(i != strCharCount.end()){
         ans += string(i->second, i->first);
         i = strCharCount.erase(i);
         if(i == strCharCount.end()){
            cout<<ans<<"\n";
            return;
         }
      }
      cout<<ans<<"\n";
      return;
   }
   cout<<ans<<"\n";
   return;
}

int main(){
   int cases=1;

   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
   scanf("%d",&cases);
   while(cases--){
      solve();
   }
   return 0;
}