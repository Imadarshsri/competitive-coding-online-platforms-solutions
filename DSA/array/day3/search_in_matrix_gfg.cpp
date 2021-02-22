#include<iostream>
#include<vector>
using namespace std;

/// Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:
/// a. Integers in each row are sorted in ascending from left to right.
/// b. Integers in each column are sorted in ascending from top to bottom.


///Problem Statement: https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1
///Solution: a) Article: https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
//           b) video: https://www.youtube.com/watch?v=ZYpYur0znng&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=13
///Concepts: 1) Efficient Soln: T(n) : O(n + m), S(n) : O(1), Observation, Intution
// Time Complexity: O(n). 
// Only one traversal is needed, i.e, i from 0 to n and j from n-1 to 0 with at most 2*n steps. 
// The above approach will also work for m x n matrix (not only for n x n). Complexity would be O(m + n). 
// Space Complexity: O(1). 
// No extra space is required.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = m - 1;
        while(j >= 0 && i < n){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target) i++;
            else j--;
        }
        return false;
    }
};


int main(){
  int n = 1, m = 1, target = 0;
  cin>>n>>m;
  vector<vector<int>> matrix(n, vector<int>(m));
  for(int i = 0; i < n; i++){
    for(int j  = 0; j < m; j++){
      cin>>matrix[i][j];
    }
  }
  cin>>target;
  cout<<Solution().searchMatrix(matrix, target);
  return 0;
}