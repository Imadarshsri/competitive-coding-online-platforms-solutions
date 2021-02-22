#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

///Problem Statement: https://leetcode.com/problems/rotate-image/
// Desc: Rotate image matrix by 90degrees clockwise
///Solution: https://www.youtube.com/watch?v=Y72QeX0Efxw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=12
///Concepts: 1) Intuition, Observation for naive
///          2) Preform these two matrix operations: a) Transpose, b) Reflect
///         Both have same time complexity, but 1st approach have less operation of read and write:
///         T(n): O(n^2), S(n): O(1)

//Your solution class
class Solution {
public: 
    void transpose(vector<vector<int>>& arr){
        int n = arr.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(arr[i][j], arr[j][i]);
            }
        }
    }
    void reflect(vector<vector<int>>& arr){
        int n = arr.size();
        for(int i = 0; i < n; i++){
            // for(int j = 0; j < n/2; j++){
            //     int temp = arr[i][j];
            //     arr[i][j] = arr[i][n - j - 1];
            //     arr[i][n - j - 1] = temp;
            // }
            reverse(arr[i].begin(), arr[i].end());
        }
    }
    
// T(n) : O(n^2) : Transposing and then Reflecting to rotate 90 degree clockwise
// if we reflect and then transpose then it will rotate 90 degree anti-clockwise
// Let M be the number of cells in the grid.

// Time complexity :  O(M). We perform two steps; transposing the matrix, and then reversing each row. Transposing the matrix has a cost of O(M) because we're moving the value of each cell once. Reversing each row also has a cost of O(M), because again we're moving the value of each cell once.
    void rotate(vector<vector<int>>& arr) {
        transpose(arr);
        reflect(arr);
    }
    
    
    
    

    // Naive Approach: Intution
    // My Solution
    // T(n) : O(n^2) : As each cell is getting read once
    // do-while loop will run for 4 times everytime
//     void rotate(vector<vector<int>>& arr) {
//         int n = arr.size();
//         for(int i = 0; i < (n/2); i++){
//             for(int j = i; j < (n-i-1); j++){
//                 int temp = arr[i][j];
//                 int previ = i, prevj = j;
//                 do{
//                     int xi = i;
//                     i = j;
//                     j = n - xi - 1;
//                     int temp1 = arr[i][j];
//                     arr[i][j] = temp;
//                     temp = temp1;
//                 }while((previ != i) || (prevj != j));
                
//                 i = previ;
//                 j = prevj;
//             }
//         }
//     }
    // Clean Solution of naive approach
    // void rotate(vector<vector<int>>& arr) {
    //     int n = arr.size();
    //     for(int i = 0; i < (n/2 + (n%2)); i++){
    //         for(int j = 0; j < (n/2); j++){
    //             int temp = arr[i][j];
    //             arr[i][j] = arr[n-1-j][i];
    //             arr[n-1-j][i] = arr[n-1-i][n-1-j];
    //             arr[n-1-i][n-1-j] = arr[j][n-1-i];
    //             arr[j][n-1-i] = temp;
    //         }
    //     }
    // }
};

int main(){
  //fastio

  int n = 1;
  cin>>n;
  vector<vector<int>> mat(n, vector<int>(n));
  Solution().rotate(mat);

  for(auto x: mat){
      for(auto y: x){
          cout<<y<<" ";
      }
      cout<<"\n";
  }
  return 0;
}