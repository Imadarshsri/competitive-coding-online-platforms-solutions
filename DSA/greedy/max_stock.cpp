#include<bits/stdc++.h>
using namespace std;

///Problem Statement: https://www.geeksforgeeks.org/buy-maximum-stocks-stocks-can-bought-th-day/
///Concepts: Greedy
///Complexity: T(n): O(nlogn) , S(n): 

bool comp(pair<int,int> &a, pair<int, int> &b) {
   if(a.first < b.first) return true;
   if(a.first > b.first) return false;
   if(a.second > b.second) return true;
   return false;
}
int solve(int arr[], int n, int amt) {
   vector<pair<int, int>> v;
   for(int i = 0; i < n; i++) {
      v.push_back({arr[i], i+1});
   }
   sort(v.begin(), v.end(), comp);

   int cost = 0, noOfStocks = 0;
   for(int i = 0; i < n && amt > 0; i++) {
      if(amt >= (v[i].first * v[i].second)) {
         amt -= (v[i].first * v[i].second);
         cost += (v[i].first * v[i].second);
         noOfStocks += v[i].second;

      }
      else {
         cost += (amt / v[i].first) * (v[i].first);
         noOfStocks += (amt / v[i].first);
         amt = 0;
      }
   }
   cout<<cost<<"\n";
   return noOfStocks;
}

int main(){
  int n=1;
  scanf("%d",&n);
  int amt = 0;
   int arr[n];
   cin >> amt;
   for(int i = 0; i < n; i++)
      cin >> arr[i];

   cout << solve(arr, n, amt);
  return 0;
}