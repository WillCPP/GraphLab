#pragma once
#include "Edge.h"
#include "Vertice.h"

class Graph
{
	Vertice **data;
	int MAXSIZE;
	Graph() {}
	Graph(int max = 100) {
		MAXSIZE = max;
		data = new Vertice*[MAXSIZE]();
	}
	~Graph() {}

	
public:
	void addNode(int *i) {}
	void removeEdge(int *i, int *j) {}
	void addEdge(int *i, int *j) {}
    bool hasEdge(int *i, int *j) {}
    int outEdge() {}
    int inEdge() {}
    void displayGraph() {}

};