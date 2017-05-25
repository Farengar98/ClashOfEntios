#pragma once
#include "Nexus.hh"

class Entio
{
public:
	Entio();
	~Entio();

	bool getState();





private:
	
	MyMap MapOBJ;
	int currentActions;
	int totalTurns;
	int fatigue = currentActions + totalTurns;
	int hitPoints;
	bool isAlive;
};

