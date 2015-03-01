#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
	vector<vector<pair<int,int> > > G;    // data structure to store graph
	int vertex_size;

public:
	Graph(int vertex_size);
	int getSize();
	int getWeightOfEdge(int head, int tail);
	vector<pair<int,int> > adjListOfVertex(int vertex);
	void addEdge(int head, int tail, int weight);
	bool removeEdge(int head, int tail);
	void printGraph();
};

Graph::Graph(int vertex_size) {
	this->vertex_size = vertex_size;
	this->G.resize(vertex_size);
}

int Graph::getSize() {
	return vertex_size;
}

int Graph::getWeightOfEdge(int head, int tail) {
	vector<pair<int,int> > edgeList = adjListOfVertex(head);
	for (int i = 0; i < edgeList.size(); i++)
		if (edgeList[i].first == tail)
			return edgeList[i].second;
	return 0;
}

vector<pair<int,int> > Graph::adjListOfVertex(int vertex) {
	return G[vertex];
}

// doesnt check for pre-existing edge, just adds a new one
void Graph::addEdge(int head, int tail, int weight) {
	G[head].push_back(make_pair(tail, weight));
}

// returns false if edge doesn't exist, otherwise deletes edge and returns true
bool Graph::removeEdge(int head, int tail) {
	vector<pair<int,int> > edgeList = adjListOfVertex(head);
	int i;
	for (i = 0; i < edgeList.size(); i++)
		if (edgeList[i].first == tail)
			break;
	if (i == edgeList.size()) {						// edge not found
		cout<<"edge not found.."<<endl;
		return false;
	}	
	edgeList.erase(edgeList.begin()+i);
	G[head] = edgeList;
	cout<<"edge deleted.."<<endl;
	return true;
}

void Graph::printGraph() {
	cout<<"adj list representation of graph.."<<endl;
	for (int i = 0; i < vertex_size; i++) {
		cout<<i<<" -> ";
		for (int j = 0; j < G[i].size(); j++)
			cout<<G[i][j].first<<" ";
		cout<<endl;
	}
}

int main() {
	Graph* G = new Graph(5);
	G->addEdge(0,1,1);
	G->addEdge(0,4,1);
	G->addEdge(1,2,1);
	G->addEdge(1,3,1);
	G->addEdge(1,4,1);
	G->addEdge(2,3,5);
	G->addEdge(3,4,1);
	G->printGraph();

	cout<<endl<<"size of graph: "<<G->getSize()<<endl;
	cout<<"weight of edge (2,3): "<<G->getWeightOfEdge(2,3)<<endl;
	cout<<"removing edge (1,3): ";G->removeEdge(1,3);
	cout<<"removing edge (4,2): ";G->removeEdge(1,3);
	cout<<endl;
	return 0;
}