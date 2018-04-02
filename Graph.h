#pragma once
#include "Edge.h"
#include "Vertice.h"

class Graph
{
	Vertice **data;
	int MAXSIZE;
	Graph() { Graph(100); }
	Graph(int max) {
		MAXSIZE = max;
		data = new Vertice*[MAXSIZE]();
	}
	~Graph() {}

	
public:
	void addNode(int i) {
		if(data[i]==nullptr)
			data[i] = new Vertice(i);
		else {
			cout << "Node already exists" << endl;
		}
	}
	Edge* removeEdge(int i, int j) {
		if (data[i] != nullptr)
			return data[i]->edges.getItem(j);
		cout << "Node does not exist" << endl;
		return nullptr;
	}
	void addEdge(int i, int j) {
		if(data[i]!= nullptr)
			data[i]->edges.addItem(j);
		else {
			cout << "Node not found, could not add edge" << endl;
		}
	}
    bool hasEdge(int i, int j) {
		if (data[i] != nullptr) {
			Edge *check = data[i]->edges.findItem(j);
			if (check == nullptr)
				return false;
			return true;
		}
		else {
			cout << "Node not found, could not find edge" << endl;
			return false;
		}
	}
	int[] outEdge(int i) {
		if (data[i] == nullptr) {
			cout << "Node not found" << endl;
			return int[0];
		}
		int size = data[i]->edges.size();
		int retArr[size];
		data[i]->edges.seeAt(0);
		for (int i = 0; i < size; i++) {
			int j = data[i]->edges.seeNext().data;
			retArr[i] = j;
		}
		return retArr;
	}
    int inEdge(int i) {}
    void displayGraph() {}

};