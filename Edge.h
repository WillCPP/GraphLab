#pragma once
class Edge {
public:
	Edge() {}
	Edge(int c) { data = c; next = nullptr; }
	~Edge() { if (next != nullptr) { delete next; next = nullptr; } }

	int data = 0;
	Edge *next = nullptr;
};