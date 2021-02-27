#include<bits/stdc++.h>
using namespace std;

///Problem Statement: 
///Solution: 
///Concepts: 
    // 1) Recursive : T(N): Exponential ? , S(N): O(Exponential) bcze of Stack of rcursion
    // 2) DP: T(N) : O(N*M), s(n): O(N*M)
    // 2.b) DP: Space Optimization of method 2:  T(N) : O(N*M), s(n): O(N)
    // 3) Combinatorics: T(N): O(min(n,m)), S(N): O(1)

//Your solution class
class Solution {
public:
    // 1) Recursive : T(N): Exponential ? , S(N): O(1)
    // int uniquePaths(int m, int n) {
    //     if(m == 1 || n == 1) 
    //         return 1;
    //     else
    //         return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    // }
    
    // 2) DP: T(N) : O(N*M), s(n): O(N*M)
    // int uniquePaths(int m, int n) {
    //     long long int paths[m][n];
    //     for(int i = 0; i < m; i++){
    //         for(int j = 0; j < n; j++){
    //             if(i == 0 || j == 0) 
    //                 paths[i][j] = 1;
    //             else 
    //                 paths[i][j] = paths[i-1][j] + paths[i][j-1];
    //         }
    //     }
    //     return paths[m-1][n-1];
    // }
    
    // 2.b) Space Optimization of method 2:  T(N) : O(N*M), s(n): O(N)
    // int uniquePaths(int m, int n) {
    //     long long int paths[n];
    //     for(int i = 0; i < m; i++){
    //         for(int j = 0; j < n; j++){
    //             if(i == 0 || j == 0) 
    //                 paths[j] = 1;
    //             else 
    //                 paths[j] += paths[j-1];
    //         }
    //     }
    //     return paths[n-1];
    // }
    
    // 3) Combinatorics: T(N): O(min(n,m)), S(N): O(1)
    int uniquePaths(int m, int n) {
        double ans = 1, r = 1;
        if(n < m)
            r = n - 1;
        else
            r = m - 1;
        
        for(int i = r; i >= 1; i--){
            ans = ans*(m + n - 2 - i + 1)/i;
        }
        return (int)round(ans);
    }
};

int main(){
  int m = 1, n = 1;
  scanf("%d %d",&m, &n);
  cout<<Solution().uniquePaths(m,n);
  return 0;
}