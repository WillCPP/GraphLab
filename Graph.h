#pragma once
#include "Node.h"

class Graph
{
	Node **data;
	int MAXSIZE;
	Graph(int max = 100) {
		MAXSIZE = max;
		data = new Node[MAXSIZE]();
	}
	~Graph() {}

	
public:
	void addNode() {}
	void removeEdge();
	void addEdge();
    bool hasEdge();
    outEdge();
    inEdge();
    displayGraph();

};