class Graph{
	private:
		list <int> *g;
		int vertices;
		// int *isVisited;
		set <int> cycles;
		void showNodes();
		int findNode(int n);
	public:
		//Constructor
		Graph(int vertics);
		//method for adding a new edge between nodes u and v
		void addEdge(int , int);
		//method for adding data to nodes
        void addData(int , int);
		//PrTing the Adjacency List Nodes of Graph
		void showGraph();
		//Method to prT DFS
		void showDFS();
		//Method to prT DFS for Disconnected Graph
		void showDisDFS();
		//Method to show whether cycle is present in graph
		void showCycleNodes();
        
		//Traversals
		void DFS(int,int isVisited[]);
		void BFS(int);
};


//Methods of Graph
Graph::Graph(int vertics){
	this->vertices = vertics;
	this->g = new list<int>[this->vertices];
	// this->addData();
	// this->showNodes();
}
////We are adding input data through a list;
void Graph::addData(int i, int x){
    // cout<<"Enter the data to the nodes of the Graph :\n";
    // for(int i=0;i<this->vertices;i++){
        // int x;
        // cout<<"\nNode "<<i<<" : ";
        // cin>>x;
        this->g[i].emplace_front(x);
    // }
}
void Graph::showNodes(){
	cout<<"\nEnter the Index of the Node to add edges shown below::";
	for(int i=0;i<this->vertices;i++){
			cout<<"\nNode "<<i<<" : "<<this->g[i].front();
	}
}
///We are adding edges by taking the index of the nodes to add edge 
void Graph::addEdge(int u,int v){
	// int u,v;
	// this->showNodes();
	// cout<<"\nEnter the Edges ::(u->from,v->to)\n";
	// cin>>u>>v;
	if(u>this->vertices || v>this->vertices) return;
	this->g[u].push_back(this->g[v].front());
	// cout<<"Edge: "<<this->g[u].front()<<" -> "<< this->g[v].front()<<" added.\n";
}

void Graph::showGraph(){
	cout<<"Graph is :: \n";
	for(int i=0;i<this->vertices;i++){
		cout<<"Root("<<i<<") :: ";
		for(auto node : this->g[i])
			cout<<node<<" -> ";
		cout<<"NULL\n";
	}
}

int Graph::findNode(int n){
	int i;
	for(i=0;i<this->vertices;i++){
		if(n==this->g[i].front()) return i;
	}
	return -1;
}

//Traversal Methods
void Graph::DFS(int n,int isVisited[]){
	int idx = this->findNode(n);
	if(idx<0 || idx >=this->vertices) return;
	// cout<<"\n"<<n<<"is at index::"<<idx;
	if(isVisited[idx] == 0){
		// cout<<this->g[idx].front()<<" ";
		isVisited[idx] = 1;
		for(auto i = this->g[idx].begin();i != this->g[idx].end();++i){
			// if(i == this->g[idx].begin()) i++;
				// cout<<"\ndfs called for "<<*i;
			if(i != this->g[idx].begin()) 
				DFS(*i, isVisited);
		}
		isVisited[idx] = 2;
		return;
	}
	else{
		// cout<<"\n val =="<<isVisited[idx]<<"->"<<this->g[idx].front()<<"\n";
		// this->cycles.insert(this->g[idx].front());
        cout<<this->g[idx].front()<<" ";
		return;
	}
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
	this->DFS(this->g[0].front(),isVisited);
}

// void Graph::BFS(int r){

// }