#pragma once
#include "Edge.h"
#include "Vertice.h"
#include <vector>
#include <list>
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
	vector<int> outEdge(int n) {
		if (data[n] == nullptr) {
			cout << "Node not found" << endl;
			return vector<int>();
		}
		int size = data[n]->edges.size();
		vector<int> retVec;
		data[n]->edges.seeAt(0);
		for (int i = 0; i < size; i++) {
			int j = data[i]->edges.seeNext()->data;
			retVec.push_back(j);
		}
		return retVec;
	}
    vector<int> inEdge(int n) {
		vector<int> retVec;
		Vertice v;
		for (int i = 0; i < MAXSIZE; i++)
		{
			v = *data[i];
			if (v.edges.findItem(n) != nullptr)
			{
				retVec.push_back(i);
			}
		}
	}
    
	void breadthFS(int i) {
		bool *visited = new bool; //vertices not visited
		list<int> queue; //queue created
		visited[i] = true; //node is visited, enqueued
		queue.push_back(i);
		
		while (!queue.empty()) { //dequeues a vertex from the queue 
			i = queue.front();
			queue.pop_front();
		}
	}
	void depthFS(int i) {}
	

};