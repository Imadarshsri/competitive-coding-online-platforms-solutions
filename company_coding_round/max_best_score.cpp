#include <bits/stdc++.h>
using namespace std;

bool comp (pair<float, int> &a, pair<float, int> &b) {
   if(a.first > b.first) return true;
   if(a.first < b.first) return false;
   if(a.second < b.second) return true;
   return false;
}

int main() {
   int n, k;
   cin>>n;
   vector<int> scores(n, 0), sum(n+1, 0), minArr(n,0);
   vector<pair<float,int>> avg;
   sum[0] = 0;
   for(int i = 0; i < n; i++) {
      cin>>scores[i];
      sum[i+1] = sum[i] + scores[i];
   }
   int mn = INT_MAX;
   for(int i = n-1; i >= 0; i--) {
      mn = min(mn, scores[i]);
      minArr[i] = mn;
   }

   for(int i = 1; i < n - 1; i++) {
      // cout<< i << ": "<< sum[n] - sum[i] << " - " << minArr[i] << " / (" << n - i - 1<< ")\n";
      avg.push_back({(float)(sum[n] - sum[i] - minArr[i])/(n - i - 1)*1.0, i});
   }

   sort(avg.begin(), avg.end(), comp);
   
   float mx = avg[0].first;
   cout<<"Ans: ";

   for(auto x: avg) {
      if(x.first == mx && x.second != 0)
         cout<<x.second<<" ";
      else 
         break;
   }
}
