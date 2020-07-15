// #include <iostream>
// #include<vector>
// #include<algorithm>
// //#include <boost/multiprecision/cpp_int.hpp>
// //using namespace boost::multiprecision;
// const int mx = 1e6 + 5;
// const long int inf = 2e9;
// typedef long long ll;
// #define rep(i, n) for (i = 0; i < n; i++)
// #define repp(i, a, b) for (i = a; i <= b; i++)
// #define pii pair<int, int>
// #define vpii vector<pii>
// #define vi vector<int>
// #define vll vector<ll>
// #define r(x) scanf("%d", &x)
// #define rs(s) scanf("%s", s)
// #define gc getchar_unlocked
// #define pc putchar_unlocked
// #define mp make_pair
// #define pb push_back
// #define lb lower_bound
// #define ub upper_bound
// #define endl "\n"
// #define fast                          \
// 	ios_base::sync_with_stdio(false); \
// 	cin.tie(NULL);                    \
// 	cout.tie(NULL);
// using namespace std;
// // void in(int &x)
// // {
// // 	register int c = gc();
// // 	x = 0;
// // 	int neg = 0;
// // 	for (; ((c < 48 || c > 57) && c != '-'); c = gc())
// // 		;
// // 	if (c == '-')
// // 	{
// // 		neg = 1;
// // 		c = gc();
// // 	}
// // 	for (; c > 47 && c < 58; c = gc())
// // 	{
// // 		x = (x << 1) + (x << 3) + c - 48;
// // 	}
// // 	if (neg)
// // 		x = -x;
// // }
// // void out(int n)
// // {
// // 	int N = n, rev, count = 0;
// // 	rev = N;
// // 	if (N == 0)
// // 	{
// // 		pc('0');
// // 		return;
// // 	}
// // 	while ((rev % 10) == 0)
// // 	{
// // 		count++;
// // 		rev /= 10;
// // 	}
// // 	rev = 0;
// // 	while (N != 0)
// // 	{
// // 		rev = (rev << 3) + (rev << 1) + N % 10;
// // 		N /= 10;
// // 	}
// // 	while (rev != 0)
// // 	{
// // 		pc(rev % 10 + '0');
// // 		rev /= 10;
// // 	}
// // 	while (count--)
// // 		pc('0');
// // }
// ll parent[mx], arr[mx], node, edge;
// vector<pair<ll, pair<ll, ll>>> v;
// void initial()
// {
// 	int i;
// 	rep(i, node + edge)
// 		parent[i] = i;
// }
// int root(int i)
// {
// 	while (parent[i] != i)
// 	{
// 		parent[i] = parent[parent[i]];
// 		i = parent[i];
// 	}
// 	return i;
// }
// void join(int x, int y)
// {
// 	int root_x = root(x); //Disjoint set union by rank
// 	int root_y = root(y);
// 	parent[root_x] = root_y;
// }
// ll kruskal()
// {
// 	ll mincost = 0, i, x, y;
// 	rep(i, edge)
// 	{
// 		x = v[i].second.first;
// 		y = v[i].second.second;
// 		if (root(x) != root(y))
// 		{
// 			mincost += v[i].first;
// 			join(x, y);
// 		}
// 	}
// 	return mincost;
// }
// int main()
// {
// 	fast;
// 	while (1)
// 	{
// 		int i, j, from, to, cost, totalcost = 0;
// 		cin >> node >> edge; //Enter the nodes and edges
// 		if (node == 0 && edge == 0)
// 			break; //Enter 0 0 to break out
// 		initial(); //Initialise the parent array
// 		rep(i, edge)
// 		{
// 			cin >> from >> to >> cost;
// 			v.pb(mp(cost, mp(from, to)));
// 			totalcost += cost;
// 		}
// 		sort(v.begin(), v.end());
// 		// rep(i,v.size())
// 		// 	cout<<v[i].first<<"  ";
// 		cout << kruskal() << endl;
// 		v.clear();
// 	}
// 	return 0;
// }

// Kruskal's algorithm in C++

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
   private:
  vector<pair<int, edge> > G;  // graph
  vector<pair<int, edge> > T;  // mst
  int *parent;
  int V;  // number of vertices/nodes in graph
   public:
  Graph(int V);
  void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void print();
};
Graph::Graph(int V) {
  parent = new int[V];

  //i 0 1 2 3 4 5
  //parent[i] 0 1 2 3 4 5
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
  // If i is the parent of itself
  if (i == parent[i])
    return i;
  else
    // Else if i is not the parent of itself
    // Then i is not the representative of his set,
    // so we recursively call Find on its parent
    return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}
void Graph::kruskal() {
  int i, uRep, vRep;
  sort(G.begin(), G.end());  // increasing weight
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    if (uRep != vRep) {
      T.push_back(G[i]);  // add to tree
      union_set(uRep, vRep);
    }
  }
}
void Graph::print() {
  cout << "Kruskal's Algorithm Minimum Soanning Tree\n(Edges present in the MST is shown in the result along with its respectives cost)\nEdge :"
     << " Weight" << endl;
  for (int i = 0; i < T.size(); i++) {
    cout << T[i].second.first << " - " << T[i].second.second << " : "
       << T[i].first;
    cout << endl;
  }
}
int main() {
  Graph g(6);
  g.AddWeightedEdge(0, 1, 4);
  g.AddWeightedEdge(0, 2, 4);
  g.AddWeightedEdge(1, 2, 2);
  g.AddWeightedEdge(1, 0, 4);
  g.AddWeightedEdge(2, 0, 4);
  g.AddWeightedEdge(2, 1, 2);
  g.AddWeightedEdge(2, 3, 3);
  g.AddWeightedEdge(2, 5, 2);
  g.AddWeightedEdge(2, 4, 4);
  g.AddWeightedEdge(3, 2, 3);
  g.AddWeightedEdge(3, 4, 3);
  g.AddWeightedEdge(4, 2, 4);
  g.AddWeightedEdge(4, 3, 3);
  g.AddWeightedEdge(5, 2, 2);
  g.AddWeightedEdge(5, 4, 3);
  g.kruskal();
  g.print();
  return 0;
}
