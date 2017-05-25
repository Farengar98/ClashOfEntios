#pragma once

class Player
{
public:
	Player();
	~Player();

private:

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

		Entio()
		{
			static const std::string Name[] = { "Carla", "Bea", "Guille", "Alessandro", "Ferrán", "Tona", "Jordi",  "Dani", "Lili", "Luci", "Roger", "Brenes"  }; //Mi array de strings que sólo existe en el scope del constructor de Entio
			currentActions = 0;
			totalTurns = 0;
			fatigue = 0;
			hitPoints = 10;
			arrows = 10;
			myWeapon = Weapon::unarmed;
			myName =  Name[rand() % 11];
		}
	};

	enum class playerState{ keepCalm, attackEntio, moveEntio, undoAction, redoAction, changeEntio };

	size_t myArmySize;

	std::priority_queue <Entio> myArmy;
};

