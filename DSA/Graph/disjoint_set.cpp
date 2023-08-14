#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/// For 0 or 1 based graphs
class DisjointSet {
    vector<int> rank, parent, size;
public: 
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // T(N): O(4*aplha) ~= O(const.)
    int findParent(int node) {
        if(node == parent[node]) 
            return node;

        return parent[node] = findParent(parent[node]); // Path Compression
    }

    // Union by rank
    void unionByRank(int u, int v) {
        int ultimateParent_u = findParent(u);
        int ultimateParent_v = findParent(v);
        
        if(ultimateParent_u == ultimateParent_v) return; // already unified or in same component

        int rank_ulp_u = rank[ultimateParent_u];
        int rank_ulp_v = rank[ultimateParent_v];
        if(rank_ulp_u > rank_ulp_v) {
            // merge v in u
            parent[ultimateParent_v] = ultimateParent_u;
            // rank will not change because the no. of component level beneath u will be almost same 
        }
        else if(rank_ulp_v > rank_ulp_u) {
            parent[ultimateParent_u] = ultimateParent_v;
        }
        else { // merge and increase rank
            parent[ultimateParent_v] = ultimateParent_u;
            rank[ultimateParent_u]++;
        }
    }  

    void unionBySize(int u, int v) {
        int ultimateParent_u = findParent(u);
        int ultimateParent_v = findParent(v);
        
        if(ultimateParent_u == ultimateParent_v) return; // already unified or in same component

        int size_ulp_u = size[ultimateParent_u];
        int size_ulp_v = size[ultimateParent_v];
        if(rank_ulp_v > rank_ulp_u) {
            parent[ultimateParent_u] = ultimateParent_v;
            size[ultimateParent_v] += size[ultimateParent_u];  // Size of u increases by nodes of v
        }
        else { // merge and increase rank
            parent[ultimateParent_v] = ultimateParent_u;
            size[ultimateParent_u] += size[ultimateParent_v];  // Size of u increases by nodes of v        }
    }  
};


int main() {
  // RANK
  DisjointSet ds(7);
  ds.unionByRank(1,2);
  ds.unionByRank(2,3);
  ds.unionByRank(4,5);
  ds.unionByRank(6,7);
  ds.unionByRank(5,6);
  /// If 3 & 7 in same component or not?
  if(ds.findParent(3) == ds.findParent(7)) {
      cout << "Rank: 3 and 7 belongs to same component" << "\n";
  }
  else {
      cout << "Rank: 3 and 7 does not belongs to same component" << "\n";
  }
  ds.unionByRank(3,7);
  /// If 3 & 7 in same component or not?
  if(ds.findParent(3) == ds.findParent(7)) {
      cout << "Rank: 3 and 7 belongs to same component" << "\n";
  }
  else {
      cout << "Rank: 3 and 7 does not belongs to same component" << "\n";
  }

  // SIZE
  DisjointSet ds2(7);
  ds2.unionBySize(1,2);
  ds2.unionBySize(2,3);
  ds2.unionBySize(4,5);
  ds2.unionBySize(6,7);
  ds2.unionBySize(5,6);
  /// If 3 & 7 in same component or not?
  if(ds2.findParent(3) == ds2.findParent(7)) {
      cout << "Size: 3 and 7 belongs to same component" << "\n";
  }
  else {
      cout << "Size: 3 and 7 does not belongs to same component" << "\n";
  }
  ds2.unionBySize(3,7);
    /// If 3 & 7 in same component or not?
  if(ds2.findParent(3) == ds2.findParent(7)) {
      cout << "Size: 3 and 7 belongs to same component" << "\n";
  }
  else {
      cout << "Size: 3 and 7 does not belongs to same component" << "\n";
  }
  return 0;
}
