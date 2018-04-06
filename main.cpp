#include <iostream>
#include <ctime>
#include <chrono>
#include "LinkedList.h"
#include "Vertice.h"
#include "Graph.h"

using namespace std;

int main() {
	

	bool quit = false;
	int choice = -1;
	bool validChoice = false;

	Graph graph;

	do
	{
		do
		{
			cout << "Which function would you like to try?" << endl;
			cout << "[1] Add Node to Graph" << endl;
			cout << "[2] Add Edge to Graph" << endl;
			cout << "[3] Remove Edge from Graph" << endl;
			cout << "[4] Find Edge in Graph" << endl;
			cout << "[5] Find Out Edges of a Node" << endl;
			cout << "[6] Find In Edges of a Node" << endl;
			cout << "[7] Display the graph as adjacency list" << endl;
			cout << "[0] Quit" << endl;
			cout << "Enter 0-8: " << endl;
			cin >> choice;
			if (choice >= 0 && choice <= 8)
			{
				validChoice = true;
			}
			else
			{
				cout << "Invalid choice." << endl;
				validChoice = false;
			}
			cout << endl;
		} while (!validChoice);

		switch (choice)
		{
		case 0: {
			cout << "Quiting..." << endl;
			quit = true;
			break; }
		case 1: {//Add Node to graph
			int in;
			cout << "Enter value of node: ";
			cin >> in;
			graph.addNode(in);
			cout << "addNode was called." << endl;
			break; }
		case 2: {//Add edge to graph
			int node;
			int edge;
			cout << "Enter value of source node: ";
			cin >> node;
			cout << "Enter value of destination node: ";
			cin >> edge;
			graph.addEdge(node,edge);
			cout << "addEdge was called" << endl;
			break; }
		case 3: {//remove an edge from graph
			int node;
			int edge;
			cout << "Enter value of source node: ";
			cin >> node;
			cout << "Enter value of destination node: ";
			cin >> edge;
			if (graph.removeEdge(node, edge) == nullptr)
				cout << "Edge was not found" << endl;;
			cout << "removeEdge was called" << endl;
			break; }
		case 4: {//Find edge in grpah
			int node;
			int edge;
			cout << "Enter value of source node: ";
			cin >> node;
			cout << "Enter value of destination node: ";
			cin >> edge;
			if (graph.hasEdge(node, edge))
				cout << "Edge does exist" << endl;
			else
				cout << "Edge does not exist" << endl;
			break; }
		case 5: {//Find out edges of node
			int in;
			cout << "Enter value of node: ";
			cin >> in;
			vector<int> outVec = graph.outEdge(in);
			cout << "outEdge was called" << endl;
			cout << "Out edges on " << in << endl;
			for (int v : outVec)
			{
				cout << v << endl;
			}
			break; }
		case 6: {//Find in edges of node
			int in;
			cout << "Enter value of node: ";
			cin >> in;
			vector<int> inVec = graph.inEdge(in);
			cout << "inEdge was called" << endl;
			cout << "In edges on " << in << endl;
			for (int v : inVec)
			{
				cout << v << endl;
			}
			break; }
		case 7: {// Display the graph as adjancency lists
			graph.displayGraph();
			break; }
		}
		cout << endl;

	} while (!quit);

	return 0;
}