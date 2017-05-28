#include "Nexus.hh"

MyMap::MyMap(myControl &myControl) : Control {myControl}
{
	std::ifstream myMapFile("default.cfg"); //Creo mi archivo file de tipo ifstream en el que cargo el contenido del documento default.cfg (el campo de juego)
	std::string currentLine;

	if (myMapFile.is_open())
	{
	int counter = 0;

	while (getline(myMapFile, currentLine))
	{
		for (int i = 0; i < currentLine.size(); i++)
		{
			myMatrix[counter][i] = currentLine[i]; //linea.at(i);
		}
		counter++;
	}
  	myMapFile.close();
	}
	else std::cout << "It's not possible to find the file you've just tried to open" << std::endl;
}


MyMap::~MyMap()
{}

void MyMap::updateMap()
{
	for (int i = 0; i < rowNum; i++)
	{
		for (int j = 0; j < colNum - 1; j++)
		{
			switch (myMatrix[i][j])
			{																	//Aplicamos color a cada caracter leído según cual sea
			case 'X': enti::cout << enti::Color::BROWN << myMatrix[i][j] << " ";																						//	
				break;
			case 'O': enti::cout << enti::Color::LIGHTBLUE << myMatrix[i][j] << " ";
				break;
			case '.': enti::cout << enti::Color::BLACK << myMatrix[i][j] << " ";
				break;
			case ':': enti::cout << enti::Color::GREEN << myMatrix[i][j] << " ";
				break;
			default:
				if (myMatrix[i][j] == '1' || myMatrix[i][j] == '2' || myMatrix[i][j] == '3' || myMatrix[i][j] == '4' || myMatrix[i][j] == '5' || myMatrix[i][j] == '6')
				{
					enti::cout << enti::Color::LIGHTMAGENTA << myMatrix[i][j] << " ";
				}
				else if(myMatrix[i][j] == 'A' || myMatrix[i][j] == 'B' || myMatrix[i][j] == 'C' || myMatrix[i][j] == 'D' || myMatrix[i][j] == 'E' || myMatrix[i][j] == 'F')
				{
					enti::cout << enti::Color::RED << myMatrix[i][j] << " ";
				}
				break;
			}
		}
		enti::cout << enti::endl;
	}
}

void MyMap::pushDraw()
{
	enti::cout << enti::cend;
}

char MyMap::charCollider()
{
	return mountain;
}

char MyMap::getContent(int positionX, int positionY)
{
	return myMatrix[positionX][positionY];
}

char MyMap::checkEnemyEntio(int positionX, int positionY)
{
	bool whoIsPlaying = myControl::thePlayers::checkPlayer();
	switch ()
	{

		char toBeDeadEntio;

		if (myMatrix[positionX][positionY] == '1')
		{
			toBeDeadEntio = myMatrix[positionX][positionY];
			return toBeDeadEntio;
		}

	}
	return 0;
}
