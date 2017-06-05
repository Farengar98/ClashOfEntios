#pragma once
#include "Nexus.hh"
#define colNum 74
#define rowNum 36

class MyMap
{
public:
	//Constructor y destructor 
	MyMap(myControl &myControl);
	~MyMap();

	void updateMap(); //Función para actualizar el mapa
	void pushDraw(); //Función para pintar cada caracter (una vez asignado el color)
	char charCollider(int index); //Función que me da acceso al atributo privado char mountar = 'X', que uso en la clase Player para comprobar la colisión de cada entio
	char getContent(int positionX, int positionY); //Función que nos devuelve el contenido del mapa en la posición X e Y que le pasamos como parámetros
	int getIndex();
	void modifyMap(int positionX, int positionY, char newChar);

private:
	char myMatrix[rowNum][colNum]; //Nuestra matriz (mapa)
	char collider[14]; //El char que funciona como colisionador de los entios
	char enemyEntio;
	myControl &Control;
};