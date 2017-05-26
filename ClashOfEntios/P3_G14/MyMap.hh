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

	bool terrainCheck(int originX, int originY, int destinyX, int destinyY, enti::InputKey direction);
	bool meleeCheck();
	
private:

	char mountain = 'X';
	char myMatrix[rowNum][colNum];
};
