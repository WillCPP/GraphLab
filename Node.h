#pragma once
#include "Edge.h"

class Node {
	Node() {}
	Node(char c) { Name = c; }
	Node(char c, Edge* e) { Name = c; edges = e; }
public:
	char Name = '0';

	Edge* edges = nullptr;
};