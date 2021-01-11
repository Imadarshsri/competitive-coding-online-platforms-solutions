#include<bits/stdc++.h>
using namespace std;
#include "./graph_adjacency_list.h"

int main(){
		int  v =6;
		Graph<float> g(v); 
		g.addEdge();//0, 1 
		g.addEdge();//0, 2 
		g.addEdge();//1, 2 
		g.addEdge();//2, 0 
		g.addEdge();//2, 3 
		g.addEdge();//3, 3 
		g.addEdge();//4, 5

		// g.showGraph();

		cout<<"DFS : ";
		g.showDFS();
		// cout<<"\nDisconnected DFS : ";
		// g.showDisDFS();
		cout<<"\nCycles in graph present at nodes :: ";
		g.showCycleNodes();
}