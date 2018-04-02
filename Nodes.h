#pragma once

template <class T>
class Nodes
{
public:
	T data;
	Nodes *next;

	Nodes(T inval) {
		data = inval;
	}
	~Nodes() {
	}
};

