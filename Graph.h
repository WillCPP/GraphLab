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
	void addNode() {}
	void removeEdge();
	void addEdge();
    bool hasEdge();
    outEdge();
    inEdge();
    void displayGraph();

};