//Traversal Methods
template <typename T>
void Graph<T>::DFS(T n,int isVisited[]){
	int idx = this->findNode(n);
	if(idx<0 || idx >=this->vertices) return;
	// cout<<"\n"<<n<<"is at index::"<<idx;
	if(isVisited[idx] == 0){
		cout<<this->g[idx].front()<<" ";
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
		this->cycles.insert(this->g[idx].front());
		return;
	}
}

template <typename T>
void Graph<T>::showCycleNodes(){
	for(auto x:this->cycles){
		cout<<x<<" ";
	}
}

template <typename T>
void Graph<T>::showDFS(){
	int *isVisited = (int *)malloc(this->vertices*sizeof(int));
	for(int i=0;i<this->vertices;i++)
		isVisited[i] = 0;
	this->DFS(this->g[0].front(),isVisited);
}

// template <typename T>
// void Graph<T>::showDisDFS(){
// 	int *isVisited = (int *)malloc(this->vertices*sizeof(int));
// 	for(int i=0;i<this->vertices;i++)
// 		isVisited[i] = 0;
// 	for(int i =0;i<this->vertices;i++)
// 		if(isVisited[i]==0){
// 			this->DFS(this->g[i].front(),isVisited);
// 		}
// }

template <typename T>
int Graph<T>::findNode(T n){
	int i;
	for(i=0;i<this->vertices;i++){
		if(n==this->g[i].front()) return i;
	}
	return -1;
}
// template <typename T>
// void Graph<T>::BFS(int r){

// }