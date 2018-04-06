#pragma once
#include "Edge.h"
#include "Vertice.h"
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;

class Graph
{
	Vertice **data;
	int MAXSIZE;
	
public:
	Graph() { 
		MAXSIZE = 100;
		data = new Vertice*[MAXSIZE]();
	}
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
			if (data[i] != nullptr)
			{
				v = *data[i];
				if (v.edges.findItem(n) != nullptr)
				{
					retVec.push_back(i);
				}
			}
		}
		return retVec;
	}
    
	void breadthFS(int i) {
		vector<bool> visited(MAXSIZE); //vertices not visited are marked
		for (int j = 0; j < MAXSIZE; j++){
			visited[j] = false;
		}
		queue<int> queue; //queue created
		visited[i] = true; //node is visited, enqueued
		queue.push(i);
		
		while (!queue.empty()) { //dequeues a vertex from the queue 
			i = queue.front();
			cout << i << " ";
			queue.pop();
			for( int j = 0; j < MAXSIZE; j++) {
				if (!visited[j]){ //if a vertice hasn't been visited, enqueue it and mark it as visited
					visited[j] = true;
					queue.push(j);
				}
			}
		}
	}
	list<int> depthFS(int i) {
		vector<bool> visited(MAXSIZE);
		stack<int> stack; //creates a stack
		stack.push(i); //will push current node
		while(!stack.empty()) {
			i = stack.top();
			stack.pop();
			if(!visited[i]){ //if not visited
			cout << i << " ";
			visited[i] = true;
			
			}
			for ( int j = 0; j < MAXSIZE; j++) { //if not visited, push in stack
				stack.push(i);
		}
	  }
	}

	void displayGraph() {
		cout << "*****Displaying Graph*****" << endl;
		cout << "Node|  Edges" << endl;
		for (int i = 0; i < MAXSIZE; i++) {
			if (data[i] != nullptr) {
				cout << endl << setw(5) << data[i]->Name;
				cout << "|";
				data[i]->edges.displayList();
			}

			//cout << "*********************" << endl;
		}
		cout << endl;
	}
};