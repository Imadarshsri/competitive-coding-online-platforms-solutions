
//Methods of Graph
template <typename T>
Graph<T>::Graph(int vertics){
	this->vertices = vertics;
	this->g = new list<T>[this->vertices];
	this->addData();
	this->showNodes();
}
////We are adding input data through a list;
template <typename T>
void Graph<T>::addData(){
		cout<<"Enter the data to the nodes of the Graph :\n";
		for(int i=0;i<this->vertices;i++){
				T x;
				cout<<"\nNode "<<i<<" : ";
				cin>>x;
				// this->g[i] =list<int>(1);
				this->g[i].emplace_front(x);
				// cout<<"data == "<<this->g[i].front();
		}
}
template <typename T>
void Graph<T>::showNodes(){
	cout<<"\nEnter the Index of the Node to add edges shown below::";
	for(int i=0;i<this->vertices;i++){
			cout<<"\nNode "<<i<<" : "<<this->g[i].front();
	}
}
///We are adding edges by taking the index of the nodes to add edge 
template <typename T>
void Graph<T>::addEdge(){
	int u,v;
	// this->showNodes();
	cout<<"\nEnter the Edges ::(u->from,v->to)\n";
	cin>>u>>v;
	if(u>this->vertices || v>this->vertices) return;
	this->g[u].push_back(this->g[v].front());
	cout<<"Edge: "<<this->g[u].front()<<" -> "<< this->g[v].front()<<" added.\n";
}

template <typename T>
void Graph<T>::showGraph(){
	cout<<"Graph is :: \n";
	for(int i=0;i<this->vertices;i++){
		cout<<"Root("<<i<<") :: ";
		for(auto node : this->g[i])
			cout<<node<<" -> ";
		cout<<"NULL\n";
	}
}