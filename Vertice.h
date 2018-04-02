#pragma once
#include "Edge.h"
#include "LinkedList.h"

class Vertice {
	Vertice() {}
	Vertice(char c) { Name = c; }
	Vertice(char c, Edge* e) { Name = c; }
public:
	char Name = '0';

	LinkedList* edges = new LinkedList<Edge>();
};