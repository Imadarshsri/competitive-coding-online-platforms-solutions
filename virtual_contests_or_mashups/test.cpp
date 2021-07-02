#include <bits/stdc++.h>
using namespace std;
#define ll long long int
/// Justpay Coding Round TSP variation (involved 2 traffic lights at each city which turns from Green to Red at every t seconds, cost of each route is c. n -> cities, m-> roads/paths)
vector<int> g[1001];
vector<pair<ll,vector<ll>>> pt;

void dfs(ll st,ll e,ll vis[],vector<ll> rs,ll w){
   rs.push_back(st);
   if(st == e){
       pt.push_back({w*(rs.size()-1),rs});
       return;
   }
   for(auto u : g[st]){
       if(vis[u] == 0){
          vis[st] = 1;
          dfs(u,e,vis,rs,w);
          vis[st] = 0;
       }
   }
}
 
void BFS(vector<int> adj[], int src, int dist[], int paths[], int n){
    bool visited[n+1];
    for (int i = 0; i <= n; i++)
        visited[i] = false;
    dist[src] = 0;
    paths[src] = 1;
 
    queue <int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
 
        // For all neighbors of current vertex do:
        for (auto x : adj[curr])
        {
            // if the current vertex is not yet
            // visited, then push it to the queue.
            if (visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
            }
 
            // check if there is a better path.
            if (dist[x] > dist[curr] + 1)
            {
                dist[x] = dist[curr] + 1;
                paths[x] = paths[curr];
            }
 
            // additional shortest paths found
            else if (dist[x] == dist[curr] + 1)
                paths[x] += paths[curr];
        }
    }
}

void findShortestPaths(vector<int> adj[],
                       int s, int n,int paths[])
{
    int dist[n+1];
   //  int  paths[n+1];
    for (int i = 0; i <= n; i++)
        dist[i] = INT_MAX;
    for (int i = 0; i <= n; i++)
        paths[i] = 0;
    BFS(g, s, dist, paths, n);
   //  cout << "Numbers of shortest Paths for "<<s <<" are: ";
   //  for (int i = 0; i <= n; i++)
   //      cout << paths[i] << " ";
    cout <<endl;


}

/// Justpay Coding Round TSP variation (involved 2 traffic lights at each city which turns from Green to Red at every t seconds, cost of each route is c. n -> cities, m-> roads/paths)
int main() {
    ll n,m,t,c,u,v;
    cin>>n>>m>>t>>c;
    while(m--){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    if(n == 1)
    cout<<0<<endl;
    else if(n == 2)
    cout<<t<<endl;
    else{
        vector<ll> rs;
        ll w = c;
        ll vis[n+1] = {0};
        dfs(1,n,vis,rs,w);
        if(pt.size() == 0)
        cout<<-1<<endl;
        else{
        sort(pt.begin(),pt.end());
        int paths1[n+1], pathsn[n+1];
        findShortestPaths(g, 1, n, paths1);
        findShortestPaths(g, n, n, pathsn);

         for (int i = 1; i <= n; i++)
            cout << paths1[i]*pathsn[i] << " ";
      } 
    }
    return 0;
}