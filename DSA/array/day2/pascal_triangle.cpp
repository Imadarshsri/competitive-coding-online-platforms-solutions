#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: https://leetcode.com/problems/pascals-triangle/
///Solution: https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=8
/// Concepts: 1) Implementation, Observation T(n): O(numRows^2)

//Macros
#define endl "\n"
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;
//Your solution class
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return vector<vector<int>>();
        vector<vector<int>> pascal(numRows);
        pascal[0] = vector<int>(1,1);
        for(int i = 1; i< numRows; i++){
            pascal[i] = vector<int>(i+1,1);
            for(int j = 1; j < i; j++){
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        return pascal;
    }
};
int main(){
  //fastio

  int cases=1;
  //fastscan(cases);
  scanf("%d",&cases);
  while(cases--){
    int n =1;
    cin>>n;
    auto ans = Solution().generate(n);
    for(auto x: ans){
      for(auto y: x){
        cout<<y<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}