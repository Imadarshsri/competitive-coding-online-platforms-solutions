#include<iostream>
#include<vector>
using namespace std;
// Search in a sorted Matix (Rows and columns are sorted such that 1st ele. of each row is greater than the last ele. of prev. row)
///Problem Statement: https://leetcode.com/problems/search-a-2d-matrix/
///Solution: https://www.youtube.com/watch?v=ZYpYur0znng&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=13
///Concepts: 1) Binary Search: T(n) : O(logn + logm), S(n) : O(1), Divide and Conquer 

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
    bool searchRow(vector<int>& row, int target){
        int l = 0, r = row.size() - 1;
        if(l == r) return row[l] == target;
        int mid = 0;
        while(l <= r){
            mid = (r-l)/2 + l;
            
            if(row[mid] == target) return true;
            else if(row[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        if(l == r) 
            return searchRow(matrix[r], target);
        int mid = 0;
        while(l <=  r){
            mid = (r-l)/2 + l;
            
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] < target) l = mid + 1;
            else r = mid - 1;
        }
        if(r >= 0)
            return searchRow(matrix[r], target);
        else 
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