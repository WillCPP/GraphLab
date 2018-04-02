#pragma once
#include <string>
using namespace std;


class UnderFlowException//Call when the list is empty and cannot see an item
{
	const string error = "List is Empty";
public:
	UnderFlowException() {};
	~UnderFlowException() {};
};
