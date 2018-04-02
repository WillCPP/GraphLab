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

	LinkedList ll;

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
			cout << "Enter 0-8: ";
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
			string f = "";
			string l = "";
			string m = "";
			double gpa = 0.0;
			int year = 0;
			int month = 0;
			int day = 0;
			cout << "Enter first name: ";
			cin >> f;
			cout << "Enter last name: ";
			cin >> l;
			cout << "Enter M-Number: ";
			cin >> m;
			cout << "Enter GPA: ";
			cin >> gpa;
			cout << "Enter birth year: ";
			cin >> year;
			cout << "Enter birth month: ";
			cin >> month;
			cout << "Enter birth day: ";
			cin >> day;
			Student s(f, l, m, Date(day, month, year), gpa);
			ll.addItem(s);
			cout << "addItem was called." << endl;
			break; }
		case 2: {//Add edge to graph
			string m = "";
			cout << "Enter M-Number: ";
			cin >> m;
			Student s("", "", m, Date(0, 0, 0), 0.0);
			Nodes<Student> *n = ll.getItem(s);
			cout << "getItem was called" << endl;
			break; }
		case 3: {//remove an edge from graph
			string m = "";
			cout << "Enter M-Number: ";
			cin >> m;
			Student s("", "", m, Date(0, 0, 0), 0.0);
			bool b = ll.isInList(s);
			if (b)
			{
				cout << "Item is in list." << endl;
			}
			else
			{
				cout << "Item is not in list." << endl;
			}
			break; }
		case 4: {//Find edge in grpah
			bool b = ll.isEmpty();
			if (b)
			{
				cout << "List is empty." << endl;
			}
			else
			{
				cout << "List is not empty." << endl;
			}
			break; }
		case 5: {//Find out edges of node
			int s = ll.size();
			cout << "Size: " << s << " items" << endl;
			break; }
		case 6: {//Find in edges of node
			ll.reset();
			cout << "reset was called" << endl;
			break; }
		case 7: {// Display the graph as adjancency lists
			ll.displayList();
			break; }
		}
		cout << endl;

	} while (!quit);

	return 0;
}