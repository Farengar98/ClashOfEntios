#include "Nexus.hh"

void main()
{
	MyMap MapOBJ;

	while (true)
	{		
		MapOBJ.updateMap();
		MapOBJ.pushDraw();
	}
}