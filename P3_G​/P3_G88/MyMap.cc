#include "stdafx.h"
#include "MyMap.hh"
#include <iostream>
#include <fstream>
#include <string>

#define colNum 74
#define rowNum 36

MyMap::MyMap()
{
	std::ifstream myMapFile("default.cfg"); //Creo mi archivo file de tipo ifstream en el que cargo el contenido del documento elements.dat
	std::string currentLine;


	while (getline(myMapFile, currentLine))
	{
		currentLine = currentLine.substr(0, colNum - 1);

	}
	myMapFile.close();
}


MyMap::~MyMap()
{
}
