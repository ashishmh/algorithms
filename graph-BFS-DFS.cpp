// Perform depth first search on a directed acyclic graph

#include <iostream>
#include <cstdio>
#include <list>
using namespace std;

class Vertex {
public:
	int id;
	Vertex(int id) {
		this->id = id;
	}
};

class Graph {
public:
	int V;			// no of vertices
	list<Vertex>* adj;
	Graph(int V) {
		this->V = V;
		adj = new list<Vertex>[V];
	}
};

void BFS();
void DFS();
void addEdge(Graph* G, int u, int v);
void printGraph(Graph* G);

void BFS(Graph* G, list<Vertex>::iterator s) {
	bool* visited = new bool[G->V];
	for (int i = 0; i < G->V; i++)
		visited[i] = false;
	// make an empty queue
	list<Vertex> queue;
	
	// mark source as visited and enqueue it
	visited[s->id] = true;
	queue.push_back(*s);
	
	list<Vertex>::iterator itr;
	while (!queue.empty()) {
		Vertex* ptr;
		ptr = &(queue.front());
		cout<<ptr->id<<" ";
		queue.pop_front();
		for (itr = G->adj[ptr->id].begin(); itr != G->adj[ptr->id].end(); itr++)
			if (!visited[itr->id]) {
				visited[itr->id] = true;
				queue.push_back(*itr);
			}
	}
}

void addEdge(Graph* G, int u, int v) {
	G->adj[u].push_back(Vertex(v));
	return;
}

void printGraph(Graph* G) {
	list<Vertex>::iterator itr;
	for (int i = 0; i < G->V; i++) {
		cout<<"\nAdjacency list of vertex "<<i<<"\nHead";
		for (itr = G->adj[i].begin(); itr != G->adj[i].end(); itr++)
			cout<<" -> "<<itr->id;
	}
	return;
}

int main() {
	// create the graph
    int V = 5;
    Graph* G = new Graph(V);
    addEdge(G, 0, 1);
    addEdge(G, 0, 4);
    addEdge(G, 1, 2);
    addEdge(G, 1, 3);
    addEdge(G, 1, 4);
    addEdge(G, 2, 3);
    addEdge(G, 3, 4);
 
    // print the adjacency list representation of the above graph
    printGraph(G);
    cout<<endl;
    list<Vertex>::iterator ptr = G->adj[0].begin();
    BFS(G, ptr);
    cout<<endl;
	return 0;
}