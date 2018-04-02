#pragma once
#include "Edge.h"
#include "Vertice.h"

class Graph
{
<<<<<<< HEAD
	Node **data;
=======
	Vertice **data;
>>>>>>> b084d49baa00b33c7423e5538e23d03ed33a9573
	int MAXSIZE;
	Graph() {}
	Graph(int max = 100) {
		MAXSIZE = max;
<<<<<<< HEAD
		data = new Node[MAXSIZE]();
=======
		data = new Vertice*[MAXSIZE]();
>>>>>>> b084d49baa00b33c7423e5538e23d03ed33a9573
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