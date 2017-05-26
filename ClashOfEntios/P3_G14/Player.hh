#pragma once
#include "Nexus.hh"

class Player
{
public:
	Player();
	~Player();

	enum class Weapon { sword, bow, unarmed };

	struct Entio
	{
		int currentActions;
		int totalTurns;
		int fatigue;
		int hitPoints;
		int arrows;
		Weapon myWeapon;
		std::string myName;
		bool isAlive;
		bool flag = true;

		Entio(int i)
		{
			if (flag)
			{
				std::string studentArmy[] = { "Carla", "Bea", "Guille", "Alessandro", "Ferrán", "Dani" }; //Mi array de strings que sólo existe en el scope del constructor de Entio
				myName = studentArmy[i];
				flag = false;
			}			
			else 
			{
				std::string teacherArmy[] = { "Tona", "Radev", "Carles", "Oscar", "Rita", "Albert" };
				myName = teacherArmy[i];
			}

			currentActions = 0;
			totalTurns = 0;
			fatigue = 0;
			hitPoints = 10;
			arrows = 10;
			myWeapon = Weapon::unarmed;
		}
	};

	friend bool operator < (const Entio &A, const Entio &B); //He sobrecargado el operador para que se considere que el Entio con menor fatiga sea el mayor

private:

	enum class playerState{ keepCalm, attackEntio, moveEntio, undoAction, redoAction, changeEntio };

	size_t myArmySize;

	std::priority_queue <Entio> myArmy;
};

