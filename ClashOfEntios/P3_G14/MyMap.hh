#pragma once
#include "Nexus.hh"
#define colNum 74
#define rowNum 36

class MyMap
{
public:
	MyMap();
	~MyMap();

	void updateMap();
	void pushDraw();

	char myMatrix[rowNum][colNum];
};
