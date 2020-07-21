#include <iostream>
#include <vector>
using namespace std;

void dfs(vector <vector<char>> &chess, int i , int j, int n , int  m){
   char c = 'B';
   if(chess[i][j] == 'B') c = 'W';
   if(i > 0 && chess[i - 1][j] == '.'){
      chess[i - 1][j] = c;
      dfs(chess, i - 1, j, n , m);
   }
   if(i < n - 1 && chess[i + 1][j] == '.'){
      chess[i + 1][j] = c;
      dfs(chess, i + 1, j, n , m);
   }
   if(j > 0 && chess[i][j - 1] == '.'){
      chess[i][j - 1] = c;
      dfs(chess, i, j - 1, n , m);
   }
   if(j < m - 1 && chess[i][j + 1] == '.'){
      chess[i][j + 1] = c;
      dfs(chess, i, j + 1, n , m);
   }
}

int main(){
   int rows = 1, cols = 1;
   cin>>rows>>cols;
   vector <vector<char>> chess(rows, vector<char>(cols));
   for(int i = 0; i< rows; i++){
      for(int j = 0; j < cols; j++){
         cin>>chess[i][j];
      }
   }
   // cout<<"bef\n";
   // for(auto x : chess){
   //    for(auto y : x){
   //       cout<<y<<" ";
   //    }
   //    cout<<"\n";
   // }
   //DFS
   bool flag = 0;
   for(int i = 0; i< rows; i++){
      for(int j = 0; j < cols; j++){
         if(chess[i][j] == '.'){
            chess[i][j] = 'B';
            dfs(chess,i,j,rows,cols);
            // flag = 1;
            // break;
         }
      }
      // if(flag) break;
   }
   // cout<<"afte r\n";
   for(auto x : chess){
      for(auto y : x){
         cout<<y;
      }
      cout<<"\n";
   }
   
   return 0;
}