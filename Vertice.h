#pragma once
#include "Edge.h"
#include "LinkedList.h"

class Vertice {
public:
	Vertice() {}
	Vertice(int c) { Name = c; }
	Vertice(int c, Edge* e) { Name = c; }

	int Name = -1;

	LinkedList edges();
};