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

	void updateMap(); //Funci�n para actualizar el mapa
	void pushDraw(); //Funci�n para pintar cada caracter (una vez asignado el color)
	char charCollider(); //Funci�n que me da acceso al atributo privado char mountar = 'X', que uso en la clase Player para comprobar la colisi�n de cada entio
	char getContent(int positionX, int positionY); //Funci�n que nos devuelve el contenido del mapa en la posici�n X e Y que le pasamos como par�metros
	char checkEnemyEntio(int positionX, int positionY); //Funci�n que usamos para comprobar si nuestro entio est� a melee del entio enemigo

private:
	char myMatrix[rowNum][colNum]; //Nuestra matriz (mapa)
	char mountain = 'X'; //El char que funciona como colisionador de los entios
	char enemyEntio;
	myControl &Control;
};
