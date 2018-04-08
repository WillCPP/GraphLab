#pragma once
class Edge {
public:
	Edge() {}
	Edge(int c) { data = c; next = nullptr; }
	~Edge() {}

	int data = 0;
	Edge *next = nullptr;
};