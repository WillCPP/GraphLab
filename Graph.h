#pragma once
#include "Edge.h"
#include "Vertice.h"

class Graph
{
	Node **data;
	Vertice **data;
	int MAXSIZE;
	Graph() {}
	Graph(int max = 100) {
		MAXSIZE = max;
		data = new Node[MAXSIZE]();
		data = new Vertice*[MAXSIZE]();
	}
	~Graph() {}

	
public:
	void addNode() {}
	void removeEdge() {}
	void addEdge() {}
    bool hasEdge() {}
    outEdge() {}
    inEdge() {}
    void displayGraph() {}

};