#pragma once
#include <string>
using namespace std;


class OverShotExcpetion//Called when seeAt location is bigger than the current lists length
{
	const string error = "That location is bigger than the list";
public:
	OverShotExcpetion() {};
	~OverShotExcpetion() {};
};
