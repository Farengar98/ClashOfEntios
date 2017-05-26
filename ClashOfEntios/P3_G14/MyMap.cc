#include "Nexus.hh"

MyMap::MyMap()
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
			myMatrix[counter][i] = currentLine[i];
		}
		counter++;
	}
  	myMapFile.close();
	}
	else std::cout << "No se encuentra el archivo que intenta abrir" << std::endl;
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
			case 'X':	enti::cout << enti::Color::BROWN << myMatrix[i][j] << " ";																						//	
				break;
			case 'O':	enti::cout << enti::Color::LIGHTBLUE << myMatrix[i][j] << " ";
				break;
			case '.': enti::cout << enti::Color::BLACK << myMatrix[i][j] << " ";
				break;
			case ':': enti::cout << enti::Color::GREEN << myMatrix[i][j] << " ";
				break;
			default:
				if (myMatrix[i][j] > '0' && myMatrix[i][i] <= '6')
				{
					enti::cout << enti::Color::LIGHTMAGENTA << myMatrix[i][j] << " ";
				}
				else enti::cout << enti::Color::RED << myMatrix[i][j] << " ";
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
