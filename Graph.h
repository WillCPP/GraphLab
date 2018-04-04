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
	list<int> outEdge(int n) {
		if (data[n] == nullptr) {
			cout << "Node not found" << endl;
			return list<int>();
		}
		int size = data[n]->edges.size();
		list<int> retList;
		data[n]->edges.seeAt(0);
		for (int i = 0; i < size; i++) {
			int j = data[i]->edges.seeNext()->data;
			retList.push_back(j);
		}
		return retList;
	}
    list<int> inEdge(int n) {
		list<int> retList;
		Vertice v;
		for (int i = 0; i < MAXSIZE; i++)
		{
			v = *data[i];
			if (v.edges.findItem(n) != nullptr)
			{
				retList.push_back(i);
			}
		}
		return retList;
	}
    
	void breadthFS(int i) {
		vector<bool>*visited = new bool[MAXSIZE]; //vertices not visited are marked
		for (int j = 0; j < n; j++){
			visited[j] = false;
		}
		list <int> queue; //queue created
		visited[i] = true; //node is visited, enqueued
		queue.push_back(i);
		
		while (!queue.empty()) { //dequeues a vertex from the queue 
			i = queue.front();
			cout << i << " ";
			queue.pop_front();
			for ( int j = 0; i < MAXSIZE; j++) {
				if (!visited[*j]){ //if a vertice hasn't been visited, enqueue it and mark it as visited
					visited[*j] = true;
					queue.push_back(*j);
				}
			}
		}
	}
	list<int> depthFS(int i) {
		vector<bool>*visited
		stack<int>stack; //creates a stack
		stack.push(i); //will push current node
		while(!stack.empty()) {
			i = stack.top();
			stack.pop();
			if(!visited[i]){ //if not visited
			cout << i << " ";
			visited[i] = true;
			
			}
			for ( int j = 0; i < MAXSIZE; j++) { //if not visited, push in stack
				stack.push(adj[i]);
		}
	  }
	}
		
	}

	void displayGraph() {
		cout << "*****Displaying Graph*****" << endl;
		cout << "Nodes|  Edges" << endl;
		for (int i = 0; i < MAXSIZE; i++) {
			if (data[i] != nullptr) {
				cout << setw(5) << data[i]->Name;
				cout << "|";
				data[i]->edges.displayList();
			}
			cout << "*********************" << endl;
		}

	}

};