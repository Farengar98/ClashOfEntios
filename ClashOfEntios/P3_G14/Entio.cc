#include "Entio.hh"



Entio::Entio()
{
	currentActions,  totalTurns = 0;
	hitPoints = 10;
	isAlive = true;
}

bool Entio::getState() 
{
	if (hitPoints < 1)
		isAlive = false;
	return isAlive;
}

Entio::~Entio()
{
}