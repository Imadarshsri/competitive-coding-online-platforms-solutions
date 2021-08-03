#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Directed Graph Adjacency List Represetation

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
   
   for (int i = 0; i < vertices; i++) {
      for ( auto x: graph[i]) {
         cout << x << " ";
      }
      cout << "\n";
   }
}