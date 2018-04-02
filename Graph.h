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
<<<<<<< HEAD
		data = new Vertice*[MAXSIZE]();
	}
	~Graph() {}

	
public:
	void addNode() {}
	void addNode(int *i) {}
	void removeEdge(int *i, int *j) {}
	void addEdge(int *i, int *j) {}
    bool hasEdge(int *i, int *j) {}
    outEdge() {}
    inEdge() {}
=======
	void addNode(int i) {
		data[i] = new Vertice(i);
	}
	void removeEdge(int i, int j) {
		data[i]->edges.getItem(j);
	}
	void addEdge(int i, int j) {
		data[i]->edges.addItem(j);
	}
    bool hasEdge(int i, int j) {}
    int outEdge() {}
    int inEdge() {}
>>>>>>> 001c2d2a0ff0c7ad8cea1c4e6e191d63b88f7d0d
    void displayGraph() {}

};