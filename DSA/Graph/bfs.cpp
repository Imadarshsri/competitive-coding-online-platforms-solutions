#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfsHepler(vector<int> g[], int i, int v, vector<bool> &vis) {
   queue <int> q;
   q.push(i);
   while(!q.empty()) {
      int node = q.front();
      vis[node] = true;
      cout << node << " ";
      q.pop();
      for(auto x: g[node]) { 
         if(!vis[x])  
            q.push(x);
      }
   }
}

// BFS
void bfs (vector<int> g[], int v) {
   vector<bool> vis(v, false);
   int componentCnt = 0;
   for(int i = 0; i < v; i++) {
      if(!vis[i]) {
         bfsHepler(g, i, v, vis);
      }
   }
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
   
   cout<< "Graph (BFS): ";
   bfs(graph, vertices);
}