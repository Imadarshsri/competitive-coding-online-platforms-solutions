#include<iostream>
#include<vector>
using namespace std;

// Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Solution: https://www.youtube.com/watch?v=eMSfBgbiEjk&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=11

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size(), minIdx = 0;
        int ans = 0;
        for(int i = 1; i < len; i++){
            if(prices[i] < prices[minIdx]){
                minIdx = i;
            }
            ans = max(ans, prices[i] - prices[minIdx]);
        }
        return ans;
    }
};

int main(){
  int n = 1;
  cin>>n;
  vector<int> prices(n);

  for(int i = 0; i< n; i++){
    cin>>prices[i];
  }
  cout<<Solution().maxProfit(prices)<<endl;
  return 0;
}