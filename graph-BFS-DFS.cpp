#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Graph {
private:
	vector<vector<pair<int,int> > > G;      // data structure to store graph
	int vertex_size;						// total no of vertices

public:
	Graph(int vertex_size);
	vector<pair<int,int> > adjListOfVertex(int vertex);
	void addEdge(int head, int tail, int weight);
	void printGraph();
	void BFS(int source);					// only traverses vertices reachable from source
	void DFS(int source);					// only traverses vertices reachable from source
	void DfsUtil(int source, bool* visited);
};

Graph::Graph(int vertex_size) {
	this->vertex_size = vertex_size;
	this->G.resize(vertex_size);
}

vector<pair<int,int> > Graph::adjListOfVertex(int vertex) {
	return G[vertex];	
}

void Graph::addEdge(int head, int tail, int weight) {
	G[head].push_back(make_pair(tail, weight));
}

void Graph::printGraph() {
	cout<<"adj list rep of graph.."<<endl;
	for (int i = 0; i < vertex_size; i++) {
		cout<<i<<" -> ";
		for (int j = 0; j < G[i].size(); j++)
			cout<<G[i][j].first<<" ";
		cout<<endl;
	}
}

void Graph::BFS(int source) {
	cout<<endl<<"BFS traversal: ";
	bool* visited = new bool[vertex_size];
	// mark all vertices as not visited initially
	for (int i = 0; i < vertex_size; i++)
		visited[i] = false;
	// make an empty queue
	deque<int> queue;
	visited[source] = true;
	queue.push_back(source);
	while (!queue.empty()) {
		// dequeue a vertex from queue and print it
		source = queue.front();
		cout<<source<<" ";
		queue.pop_front();
		// iterator for elements of adj list i.e of type pair
		vector<pair<int,int> >::iterator i;
		for (i = G[source].begin(); i < G[source].end(); i++)
			if (!visited[i->first]) {
				visited[i->first] = true;
				queue.push_back(i->first);
			}
	}
}

void Graph::DFS(int source) {
	cout<<endl<<"DFS traversal: ";
	bool *visited = new bool[vertex_size];
	for (int i = 0; i < vertex_size; i++)
		visited[i] = false;
	DfsUtil(source, visited);
}

void Graph::DfsUtil(int source, bool* visited) {
	visited[source] = true;
	cout<<source<<" ";
	vector<pair<int,int> >::iterator i;
	for (i = G[source].begin(); i != G[source].end(); i++)
		if (!visited[i->first])
			DfsUtil(i->first, visited);
}

int main() {
	Graph* G = new Graph(5);
	// adding edges
	G->addEdge(0,1,1);
	G->addEdge(0,4,1);
	G->addEdge(1,2,1);
	G->addEdge(1,3,1);
	G->addEdge(1,4,1);
	G->addEdge(2,4,1);
	G->addEdge(2,3,1);
	G->addEdge(3,4,1);
	G->printGraph();

	G->BFS(1);
	G->DFS(1);
	cout<<endl<<endl;
	return 0;
}