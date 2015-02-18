// Create a graph using Adjacency list representation and print it

#include <iostream>
#include <cstdio>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

class LinkedList {
public:
	Node* head;
	LinkedList() {
		head = NULL;
	}
};

class Graph {
public:
	int V;
	LinkedList* adj[];
	Graph(int V) {
		this->V = V;
		for (int i=0; i<V; i++)
			adj[i] = new LinkedList();
	}
};

void addEdge(Graph* G, int u, int v);
void printGraph(Graph* G);

void addEdge(Graph* G, int u, int v) {
	Node* new_node = new Node(v);
	new_node->next = G->adj[u]->head;
	G->adj[u]->head = new_node;

	new_node = new Node(u);
	new_node->next = G->adj[v]->head;
	G->adj[v]->head = new_node;
	return;
}

void printGraph(Graph* G) {
	for (int i = 0; i < G->V; i++) {
		Node* head = G->adj[i]->head;
		cout<<"\nAdjacency list of vertex "<<i<<"\nHead ";
		while (head->next) {
			cout<<" -> "<<head->data;
			head = head->next;
		}
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
	return 0;
}