// Topological sorting of a directed acyclic graph
// match output from here: http://www.geeksforgeeks.org/topological-sorting/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
	vector<vector<pair<int,int> > > G;      // data structure to store graph
	int vertex_size;						// total no of vertices

public:
	Graph(int vertex_size);
	void addEdge(int head, int tail, int weight);
	void printGraph();
	void topologicalSort();
	void topologicalSortUtil(int i, bool* visited, stack<int>* stack);
};

Graph::Graph(int vertex_size) {
	this->vertex_size = vertex_size;
	this->G.resize(vertex_size);
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

void Graph::topologicalSort() {
	cout<<endl<<"topological sorted list: ";
	bool* visited = new bool[vertex_size];
	for (int i = 0; i < vertex_size; i++)
		visited[i] = false;
	stack<int> stack;
	for (int i = 0; i < vertex_size; i++)
		if (!visited[i])
			topologicalSortUtil(i, visited, &stack);
	while (!stack.empty()) {
		cout<<stack.top()<<" ";
		stack.pop();
	}
}

void Graph::topologicalSortUtil(int i, bool* visited, stack<int>* stack) {
	visited[i] = true;
	vector<pair<int,int> >::iterator itr;
	for (itr = G[i].begin(); itr != G[i].end(); itr++) {
		if (!visited[itr->first])
			topologicalSortUtil(itr->first, visited, stack);
	}
	stack->push(i);
}

int main() {
	Graph* G = new Graph(6);
	// adding edges
	G->addEdge(5, 2, 1);
    G->addEdge(5, 0, 1);
    G->addEdge(4, 0, 1);
    G->addEdge(4, 1, 1);
    G->addEdge(2, 3, 1);
    G->addEdge(3, 1, 1);
	G->printGraph();

	G->topologicalSort();
	cout<<endl<<endl;
	return 0;
}