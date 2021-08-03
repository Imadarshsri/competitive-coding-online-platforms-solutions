#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

vector<int> extractArray (string &s) {
   vector<int> arr;
   int n = s.length();
   int i = 1;
   while(i < n-1) {
      int l = i;
      while(s[i] != ',' && i < n - 1)
         i++;
         
      arr.push_back(atoi(s.substr(l, i).c_str()));
      i++;
   }
   return arr;
}

int main () {

   /// Test program to read all piped input into a string, then write it out again:
   
   // istreambuf_iterator<char> begin(cin), end;
   // string s(begin, end);
   // cout << s;


   string ip;
   getline(cin, ip);
   cout << "i/p: " << ip;
   vector <int> arr = extractArray(ip);
   cout << "\n arr []: ";
   for(auto x : arr) {
      cout << x << " ";
   }
   cout << "\n";
   return 0;
}