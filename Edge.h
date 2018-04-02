#pragma once
class Edge {
	Edge() {}
	Edge(char c) { Name = c; }
public:
	char Name = '0';
	Edge *pNext = nullptr;
};