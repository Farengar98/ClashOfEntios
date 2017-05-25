#include "Nexus.hh"

void main()
{
	//setup
	MyMap MapOBJ;


	//iniciar gameLoop
	while (true)
	{		
		MapOBJ.updateMap();
		//meter en el buffer el character actual i el numero de acciones restantes
		MapOBJ.pushDraw();
	}
}