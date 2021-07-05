#include <bits/stdc++.h>
using namespace std;
  
  
  void dfs(int i,vector<int> g[],  vector<bool> &vis) {
    vis[i] = true;
    
    for(auto x: g[i]) {
      if(!vis[x])
        dfs(x, g, vis);
    }
  }
  void printGraph(vector<int> g[], int n) {
    
    for(int i = 1; i <= n; i++) {
      cout<< i<< ": ";
      for(auto x: g[i]) {
        cout<< x << ", ";
      }
      cout<<"\n";
    }
  }
  
  void transpose(vector<int> g[], int n, vector<int> gT[]) {
    for(int i = 1; i <= n; i++) {
      for(auto x: g[i]) {
        gT[x].push_back(i);
      }
    }
  }
  
  
  string solve(){
    int n = 1, m = 1;

    cin >> n >> m;
    
    
    vector<int> g[n+1];
    
    for(int i = 0; i < m; i++) {
      int u, v;
      cin>>u>>v;
      g[u].push_back(v);
    }
    
    vector<bool> vis1(n+1, false), vis2(n+1, false);
    
    //dfs with vis1
    dfs(1, g, vis1);
    
    // printGraph(g,n);
    
    // transpose
    
    vector<int> gT[n + 1];
    
    transpose(g, n, gT);
    
    // printGraph(gT,n);
    
    // dfs with vis2
    dfs(1, gT, vis2);
    
    for(int i = 1; i <= n; i++) {
      if(!vis1[i] || !vis2[i]) /// ??
        return "NO";
    }

    return "YES";
  }
  
  int main() {
    int t = 1;
    cin>>t;
    while(t--) {
      cout<<solve()<<"\n";
    }
    return 0;
  }