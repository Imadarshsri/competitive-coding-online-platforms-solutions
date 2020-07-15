#include<bits/stdc++.h>
using namespace std;
//Directed Graph
class Graph{
	private:
		list<int> *g;
		int vertices;
		// int *isVisited;
		set<int> cycles;
		void DFS(int , int isVisited[]);
		void BFS(int);
	public:
		//Constructor
		Graph(int vertics);
		//method for adding a new edge between nodes u and v
		void addEdge(int u, int v);
		//Printing the Adjacency List Nodes of Graph
		void showGraph();
		//Method to print DFS
		void showDFS();
		//Method to print DFS for Disconnected Graph
		void showDisDFS();
		//Method to show whether cycle is present in graph
		void showCycleNodes();
};

//Methods of Graph
Graph::Graph(int vertics){
	this->vertices = vertics;
	this->g = new list<int>[this->vertices];
}

void Graph::addEdge(int u, int v){
	this->g[u].push_back(v);
}

void Graph::showGraph(){
	cout<<"Graph is :: \n";
	for(int i=0;i<this->vertices;i++){
		cout<<"Root("<<i<<") -> ";
		for(auto node : this->g[i])
			cout<<node<<" -> ";
		cout<<"\n";
	}
}

void Graph::DFS(int n,int isVisited[]){
	if(isVisited[n] == 0){
		cout<<n<<" ";
		isVisited[n] = 1;
		for(auto node : this->g[n])
				DFS(node, isVisited);
		isVisited[n] = 2;
	}
	else
		this->cycles.insert(n);
}

void Graph::showCycleNodes(){
	for(auto x:this->cycles){
		cout<<x<<" ";
	}
}

void Graph::showDFS(){
	int *isVisited = (int *)malloc(this->vertices*sizeof(int));
	for(int i=0;i<this->vertices;i++)
		isVisited[i] = 0;
	this->DFS(0,isVisited);
}

void Graph::showDisDFS(){
	int *isVisited = (int *)malloc(this->vertices*sizeof(int));
	for(int i=0;i<this->vertices;i++)
		isVisited[i] = 0;
	for(int i =0;i<this->vertices;i++)
		if(isVisited[i]==false)
			this->DFS(i,isVisited);
}

void Graph::BFS(int r){

}
