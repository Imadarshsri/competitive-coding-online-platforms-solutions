#include<iostream>
#include<vector>
using namespace std;

///Problem Statement: https://leetcode.com/problems/set-matrix-zeroes/
///Solution: https://www.youtube.com/watch?v=M65xBewcqcI&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=7
/// Concetps: 0) Naive : T(n): O(3mn), S(n): O(m+n)
//            1) Better: Using dummy arrays for setting rows and cols flags of cells with zero value
///           2) Optimal: Using matrix itself for marking flags of rows and cols: T(n): O(2mn + m + n), S(n): O(1)

//Macros
#define endl "\n"
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

typedef uint64_t ui;

class Solution {
public:
    //Solution with T(n): O(2mn + m + n), S(n): O(1)
     void setZeroes(vector<vector<int>>& matrix) {
        bool firstCol = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0) firstCol = true;
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                   matrix[i][j] = 0;
                }
             }
        }
        
        if(matrix[0][0] == 0){
            for(int j = 0; j <  n;j++){
                   matrix[0][j] = 0;
            }
        }
        if(firstCol)
           for(int i = 0; i < m; i++){
               matrix[i][0] = 0;
            }
     }
    //Solution with T(n): O(3mn), S(n): O(m+n)
    // // Easy Approach
    // void setZeroes(vector<vector<int>>& matrix) {
    //     set<int> is, js;
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     for(int i = 0; i < m; i++){
    //         for(int j = 0; j<n ; j++){
    //             if(matrix[i][j] == 0){
    //                 is.insert(i);
    //                 js.insert(j);
    //             }
    //         }
    //     }
    //     for(int i = 0; i < m; i++){
    //         for(int j = 0; j<n ; j++){
    //             if((is.find(i) != is.end()) || (js.find(j) != js.end())){
    //                matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }
};

int main(){
  //fastio

  int cases=1;
  int n, cols ;
  cin>>n>>cols;
  vector<vector<int>> matrix(n);
  for(int i = 0; i < n; i++){
    matrix[i] = vector<int>(cols);
    for(int j = 0; j < cols; j++){
      cin>>matrix[i][j];
    }
  }
  //fastscan(cases);
  // scanf("%d",&cases);
  while(cases--){
    Solution().setZeroes(matrix);
  }
  return 0;
}