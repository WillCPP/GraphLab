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
<<<<<<<<< saved version
		data = new Vertice*[MAXSIZE]();
	}
	~Graph() {}

	
public:
	void addNode() {}
=========
	void addNode(int *i) {}
	void removeEdge(int *i, int *j) {}
	void addEdge(int *i, int *j) {}
    bool hasEdge(int *i, int *j) {}
>>>>>>>>> local version
    outEdge() {}
    inEdge() {}
    void displayGraph() {}

};