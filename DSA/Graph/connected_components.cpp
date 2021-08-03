#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int> g[], int i, int v, vector<bool> &vis) {
   vis[i] = true;
   for(auto x: g[i]) {
      if(!vis[x]) 
         dfs(g, x, v, vis);
   }
}

// Connected Components
int numberOfComponents (vector<int> g[], int v) {
   vector<bool> vis(v, false);
   int componentCnt = 0;
   for(int i = 0; i < v; i++) {
      if(!vis[i]) {
         componentCnt++;
         dfs(g, i, v, vis);
      }
   }
   return componentCnt;
}

int main () {
   int vertices = 1;
   cin >> vertices;
   vector<int> graph[vertices];
   int edges = 0;
   cin >> edges;

   while (edges--) {
      int x, y;
      cin >> x >> y;
      graph[x].push_back(y);
   }
   
   cout<< "No. of Components: " << numberOfComponents(graph, vertices);
}