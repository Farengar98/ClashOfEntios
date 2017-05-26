#include "Nexus.hh"

Player::Player()
{
	myArmySize = 6;

	for(int i = 0; i < myArmySize; i++)
	{
		Entio A(i);
		myArmy.push(A);
	}
}

Player::~Player()
{}

bool operator < (const Player::Entio & A, const Player::Entio & B)
{
	if (A.fatigue < B.fatigue)
		return B < A;
}
