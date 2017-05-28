#include "Nexus.hh"

myControl::myControl(MyMap &myMatrix) : Matrix {myMatrix}
{
	thePlayers A; // = { 10, , 6, currentEntio, true, playerState::keepCalm }; ??
	A.remainingActions = 10;
	A.myArmySize = 6;
	A.myTurn = true;
	A.state = playerState::keepCalm;
	A.lastKeyPressed = enti::InputKey::NONE;
	A.tag = true;
	
	for (int i = 0; i < A.myArmySize; i++)
	{
		Entio student(i, true);
		A.myArmy.push(student);
	}
	A.currentEntio = A.myArmy.top();

	thePlayers B;
	//remainingActions no debería hacer falta inicializarlo aquí (cuando toca turno, remainingActions = 10)
	B.myArmySize = 6;
	B.myTurn = false;
	B.state = playerState::notMyTurn;
	//lastKeyPressed no debería hacer falta inicializrlo aquí (misma razón que remaining actions)
	B.tag = false;
	for (int i = 0; i < A.myArmySize; i++)
	{
		Entio teacher(i, false);
		B.myArmy.push(teacher);
	}
	//Tampoco hay ningun currentEntio mientras no estés en tu turno (misma razón que remaining actions)
}

myControl::~myControl()
{}

bool myControl::thePlayers::checkPlayer()
{
	if (tag)
		return true;
	
	return false;
}

void myControl::thePlayers::keepCalm()
{
	while(state != playerState::endTurn)
	{
		switch(state)
		{
		case playerState::attackEntio: attackEntio(lastKeyPressed);
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


void myControl::thePlayers::attackEntio(enti::InputKey direction)

{
	bool possibleToAttack;
	possibleToAttack = currentEntio.meleeCheck(direction);
}

void myControl::thePlayers::moveEntio()
{

}

void myControl::thePlayers::undoAction()
{

}

void myControl::thePlayers::redoAction()
{

}

void myControl::thePlayers::changeEntio()
{

}

void myControl::thePlayers::endTurn()
{

}

bool operator < (const myControl::Entio & A, const myControl::Entio & B)
{
	if (A.fatigue < B.fatigue)
		return B < A;
}

bool myControl::Entio::terrainCheck(int originX, int originY, int destinyX, int destinyY, enti::InputKey direction)
{
	if (direction == enti::InputKey::w || direction == enti::InputKey::W)
	{
		for (int i = originX, j = originY; j > destinyY; j--)
		{
			if (Matrix.getContent(i, j) == Matrix.charCollider()) return false;
		}
	}
	else if (direction == enti::InputKey::s || direction == enti::InputKey::S)
	{
		for (int i = originX, j = originY; j < destinyY; j++)
		{
			if (Matrix.getContent(i, j) == Matrix.charCollider()) return false;
		}
	}
	else if (direction == enti::InputKey::a || direction == enti::InputKey::A)
	{
		for (int i = originX, j = originY; i > destinyX; i--)
		{
			if (Matrix.getContent(i, j) == Matrix.charCollider()) return false;
		}
	}
	else if (direction == enti::InputKey::d || direction == enti::InputKey::D)
	{
		for (int i = originX, j = originY; i < destinyX; i++)
		{
			if (Matrix.getContent(i, j) == Matrix.charCollider()) return false;
		}
	}
	else return true;
}

bool myControl::Entio::meleeCheck(enti::InputKey direction)
{
	if (isPlaying)
	{
		switch(direction)
		{
		case enti::InputKey::w: 
		case enti::InputKey::W:

			if (Matrix.getContent(positionX, positionY - 1) == Matrix.checkEnemyEntio(positionX, positionY - 1))
			{
				return true;
			}
			break;

		case enti::InputKey::s:
		case enti::InputKey::S:
			
			if (Matrix.getContent(positionX, positionY + 1) == Matrix.checkEnemyEntio(positionX, positionY + 1))
			{
				return true;
			}
			break;

		case enti::InputKey::a:
		case enti::InputKey::A:
			
			if (Matrix.getContent(positionX - 1, positionY) == Matrix.checkEnemyEntio(positionX, positionY + 1))
			{
				return true;
			}
			break;

		case enti::InputKey::d:
		case enti::InputKey::D:

			if (Matrix.getContent(positionX + 1, positionY) == Matrix.checkEnemyEntio(positionX + 1, positionY))
			{
				return true;
			}
			break;

		default: return false;
			break;
	}
}

