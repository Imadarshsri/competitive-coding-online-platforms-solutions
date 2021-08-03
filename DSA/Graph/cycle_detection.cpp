#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool dfsHelper(vector<int> g[], int i, int parent, int v, vector<bool> &vis) {
   vis[i] = true;
   cout << i << " ";
   for(auto x: g[i]) {
      if(!vis[x]) 
         if(dfsHelper(g, x, i, v, vis))
            return true;
      else if(x != parent)
         return true;
   }
   return false;
}

// DFS
bool isCycleDFS (vector<int> g[], int v) {
   vector<bool> vis(v, false);
   int componentCnt = 0;
   for(int i = 0; i < v; i++) {
      if(!vis[i]) {
         if(dfsHelper(g, i, -1, v, vis))
            return true;
      }
   }
   return false;
}


bool bfsHelper(vector<int> g[], int i, int v, vector<bool> &vis) {
   queue <pair<int,int>> q;
   q.push({i, -1});
   while(!q.empty()) {
      pair<int, int> node = q.front();
      vis[node.first] = true;
      cout << node.first << " ";
      q.pop();
      for(auto x: g[node.first]) { 
         if(!vis[x])  
            q.push({x, node.first});
         else if(x != node.second)
            return true;
      }
   }
   return false;
}

// BFS
bool isCycleBFS (vector<int> g[], int v) {
   vector<bool> vis(v, false);
   int componentCnt = 0;
   for(int i = 0; i < v; i++) {
      if(!vis[i]) {
         if(bfsHelper(g, i, v, vis))
            return true;
      }
   }
   return false;
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
   
   cout<< "Is cycle Present: " << isCycleDFS(graph, vertices);
   cout<< "Is cycle Present: " << isCycleBFS(graph, vertices);
}