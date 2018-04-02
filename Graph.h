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
	void addNode(int i) {
		data[i] = new Vertice(i);
	}
	void removeEdge(int i, int j) {
		data[i]->edges.getItem(j);
	}
	void addEdge(int i, int j) {
		data[i]->edges.addItem(j);
	}
    bool hasEdge(int i, int j) {
		data[i]->edges.findItem(j);
	}
    int[] outEdge() {
		int size = data[i]->edges.size();
		int retArr[size];
		data[i]->edges.seeAt(0);
		for (int i = 0; i < size; i++) {
			int j = data[i]->edges.seeNext().data;
			retArr[i] = j;
		}
		return retArr;
	}
    int inEdge() {}
    void displayGraph() {}

};