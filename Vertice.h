#pragma once
#include "Edge.h"
#include "LinkedList.h"

class Vertice {
	Vertice() {}
	Vertice(int c) { Name = c; }
	Vertice(int c, Edge* e) { Name = c; }
public:
	int Name = -1;

	LinkedList* edges = new LinkedList();
};