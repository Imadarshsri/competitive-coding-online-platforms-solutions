#include<bits/stdc++.h>
using namespace std;
//Directed Graph
template <typename T>
class Graph{
	private:
		list <T> *g;
		int vertices;
		// T *isVisited;
		set <T> cycles;
		//method for adding data to nodes
		void addData();
		void showNodes();
		int findNode(T n);
		//Traversals
		void DFS(T,int isVisited[]);
		void BFS(int);
	public:
		//Constructor
		Graph(int vertics);
		//method for adding a new edge between nodes u and v
		void addEdge();
		//PrTing the Adjacency List Nodes of Graph
		void showGraph();
		//Method to prT DFS
		void showDFS();
		//Method to prT DFS for Disconnected Graph
		void showDisDFS();
		//Method to show whether cycle is present in graph
		void showCycleNodes();
};
#include "./graph_basic_methods.tpp"
#include "./graph_dfs.tpp"