#pragma once
#include "Edge.h"
#include "Vertice.h"
#include <vector>
using namespace std;

class Graph
{
	Vertice **data;
	int MAXSIZE;
public:
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
	vector<int> outEdge(int i) {
		if (data[i] == nullptr) {
			cout << "Node not found" << endl;
			return vector<int>();
		}
		int size = data[i]->edges.size();
		vector<int> retArr;
		data[i]->edges.seeAt(0);
		for (int i = 0; i < size; i++) {
			int j = data[i]->edges.seeNext()->data;
			retArr.push_back(j);
		}
		return retArr;
	}
    vector<int> inEdge(int i) {}
    
	void breadthFS(int i) {
		bool *visited  = new bool //vertices not visited
		list <int> queue; //queue created
		visited[i] = true; //node is visited, enqueued
		queue.push_back(i);
		
		while (!queue.empty()) { //dequeues a vertex from the queue 
			i = queue.front();
			queue.pop_front();
		}
	}
	void depthFS(int i) {}
	
<<<<<<< HEAD


=======
>>>>>>> 6e6fb892a32a82489e7c4dc058183014368d55b7
};