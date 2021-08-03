#include <iostream>
using namespace std;
//Defining number for vertices for graph
#define vertices 4
#define INFINITY 99999

///Adjacency Matrix Representation of Graph and their respective cost for Edges
int graph[vertices][vertices] = {
	{0, 5, 1, 2},
	{5, 0, 3, 3},
	{1, 3, 0, 4},
	{2, 3, 4, 0}
};

///MINIMUM SPANNING TREE STRUCTURE or MST
struct mst{
	bool visited;
	int key;
	int near;
};

//MST Array
mst MST_Array[vertices];

//Method to initialize MST Array
void initializeMST(){
	for (int i = 0; i < vertices; i++){
		MST_Array[i].visited = false;
		MST_Array[i].key = INFINITY; // considering INFINITY as inifinity
		MST_Array[i].near = i;
	}

	MST_Array[0].key = 0;
}

///Method for adding Vertices or node and updating the cost of respective connected Edges
void updateMST(){
	for (int v = 0; v < vertices; v++){
		int min = INFINITY;
		int minIndex = 0;
		for (int i = 0; i < vertices; i++){
			if (MST_Array[i].key < min && MST_Array[i].visited == false && MST_Array[i].key != INFINITY){
				min = MST_Array[i].key;
				minIndex = i;
			}
		}

		MST_Array[minIndex].visited = true;

		for (int i = 0; i < vertices; i++){
			if (graph[minIndex][i] != 0 && graph[minIndex][i] < INFINITY){
				if (graph[minIndex][i] < MST_Array[i].key){
					MST_Array[i].key = graph[minIndex][i];
					MST_Array[i].near = minIndex;
				}
			}
		}
	}
}

///Displaying Minimum Spanning Tree Edges
void show_MSTEdges(){
  cout<<"Minimum Spanning Tree Representation through existing path (Prim's Algorithm)::\n\n";
  cout<<" Path (u <--> v)   |  Minimum Cost \n";
  cout<<"  u     |    v     |(Between u and v)\n---------------------------------------\n  ";
	for (int i = 0; i < vertices; i++){
		cout << i <<"     |    "<< MST_Array[i].near << "     |    " << graph[i][MST_Array[i].near] << "\n  ";
	}
}

///Main Function
int main(){
	initializeMST();
	updateMST();
	show_MSTEdges();
	return 0;
}
Minimum Spanning Tree Representation through existing path (Prim's Algorithm)::

 Path (u <--> v)   |  Minimum Cost
  u     |    v     |(Between u and v)
---------------------------------------
  0     |    0     |    0
  1     |    2     |    3
  2     |    0     |    1
  3     |    0     |    2