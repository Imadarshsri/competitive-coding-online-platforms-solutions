#include<bits/stdc++.h>
using namespace std;

void dfs (int root, int parent, int n, vector<vector<int>> &g) {
   for(int j = 0; j < n; j++) {
      if(g[root][j] > 0) {
         if(g[parent][root] >= g[root][j]) {

            int debt = g[root][j];
            g[parent][root] -= debt;
            g[parent][j] += debt;
            g[root][j] = 0;
         }
         else {
            int debt = g[parent][root];
            g[root][j] -= debt;
            g[parent][j] += debt;
            g[parent][root] = 0;
         }
      }
   }
}

int main() {
   int n = 5;
   // cin >> n;
   vector<vector<int>> g = { {0, 100, 30, 0, 0}, 
                              {0, 0, 0, 50, 0}, 
                              {0, 0, 0, 50, 0}, 
                              {0, 0, 0, 0, 100}, 
                              {0, 0, 0, 0, 0} };
                              
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         if(g[i][j] > 0)
            dfs(j, i, n, g);
      }
   }

   for(int i = 0; i < n; i++) {

      for(int j = 0; j < n; j++) {
         cout<< g[i][j] << " ";
      }
      cout << endl;
   }
}