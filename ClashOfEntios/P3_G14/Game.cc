#include "Nexus.hh"

void main()
{
	//setup
	MyMap MapOBJ;
	std::priority_queue <Entio> entios;


	//iniciar gameLoop
	while (true) {

		
		MapOBJ.drawMap();
		//meter en el buffer el character actual i el numero de acciones restantes
		MapOBJ.pushDraw();
	}
}