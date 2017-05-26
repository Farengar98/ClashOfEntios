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

void Player::keepCalm()
{
	playerState state;

	while(state != playerState::endTurn)
	{
		switch(state)
		{
		case playerState::attackEntio: attackEntio();
			break;
		case playerState::changeEntio: changeEntio();
			break;
		case playerState::moveEntio: moveEntio();
			break;
		case playerState::undoAction: undoAction();
			break;
		case playerState::redoAction: redoAction();
			break;
		default:
			break;
		}
	}
}

void Player::attackEntio(enti::InputKey direction)
{

}

void Player::moveEntio()
{
}

void Player::undoAction()
{
}

void Player::redoAction()
{
}

void Player::changeEntio()
{
}

void Player::endTurn()
{
}

bool operator < (const Player::Entio & A, const Player::Entio & B)
{
	if (A.fatigue < B.fatigue)
		return B < A;
}
