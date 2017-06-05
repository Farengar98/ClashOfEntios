#include "Nexus.hh"

myControl::myControl(MyMap &myMatrix) : Matrix {myMatrix} 
{
	student.remainingActions = 10;
	student.myArmySize = 6;
	student.myTurn = true;
	student.state = playerState::keepCalm;
	student.lastKeyPressed = enti::InputKey::NONE;
	student.tag = true;
/*
	for (int i = 0, j = 65; j < 71; i++, j++)
		student.enemyEntios[i] = j;
*/		
	for (int i = 0; i < student.myArmySize; i++)
	{
		Entio A(i, true);
		student.myArmy.push_back(A);
	}
	student.currentEntio = student.myArmy.front();

	//remainingActions no debería hacer falta inicializarlo aquí (cuando toca turno, remainingActions = 10)
	teacher.myArmySize = 6;
	teacher.myTurn = false;
	teacher.state = playerState::notMyTurn;
	//lastKeyPressed no debería hacer falta inicializrlo aquí (misma razón que remaining actions)
	teacher.tag = false;
	
/*	for (int i = 0, j = 49; j < 55; i++, j++)
		teacher.enemyEntios[i] = j;
*/
	for (int i = 0; i < teacher.myArmySize; i++)
	{
		Entio B(i, false);
		teacher.myArmy.push_back(B);
	}
	//Tampoco hay ningun currentEntio mientras no estés en tu turno (misma razón que remaining actions)
}

myControl::~myControl()
{}

bool myControl::thePlayer::checkPlayer()
{
	if (tag)
		return true;
	return false;
}

void myControl::thePlayer::keepCalm(enti::InputKey keyPressed)
{
	while(state != playerState::endTurn)
	{
		switch (keyPressed)
		{
		case enti::InputKey::SPACEBAR: state = playerState::attackEntio;
			break;

		case enti::InputKey::ENTER: 
			if(remainingActions > 0)
				state = playerState::changeEntio;
			else state = playerState::endTurn;
			break;

		case enti::InputKey::w:
		case enti::InputKey::W:
		case enti::InputKey::s:
		case enti::InputKey::S:
		case enti::InputKey::a:
		case enti::InputKey::A:
		case enti::InputKey::d:
		case enti::InputKey::D:
			state = playerState::moveEntio;
			break;

		case enti::InputKey::z:
		case enti::InputKey::Z:	
			state = playerState::undoAction;
			break;

		case enti::InputKey::X:
		case enti::InputKey::x:
			state = playerState::redoAction;
			break;
		default:
			break;
		}

		switch(state)
		{
		case playerState::attackEntio: 
			enti::cout << enti::Color::WHITE << "What weapon would you like to use?" << enti::endl;
			enti::InputKey weapon;
			weapon = enti::getInputKey();
			attackEntio(weapon);
			break;
		case playerState::changeEntio: changeEntio();
			break;
		case playerState::moveEntio: moveEntio(keyPressed);
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

void myControl::thePlayer::attackEntio(enti::InputKey weapon)
{
	bool possibleToAttack;
	enti::InputKey direction;

	if (weapon == enti::InputKey::NUM1)
	{
		enti::cout << "The weapon you've chosen is the sword" << enti::endl << enti::endl;
		currentEntio.myWeapon = Weapon::sword;
		enti::cout << enti::Color::YELLOW << "For the direction of the attack type:" << enti::endl;
		enti::cout << "1 - Up" << enti::endl;
		enti::cout << "2 - Left" << enti::endl;
		enti::cout << "3 - Down" << enti::endl;
		enti::cout << "4 - Right" << enti::endl;
		direction = enti::getInputKey();
		if (direction == enti::InputKey::NUM1)
		{
			if (tag)
			{
				for (int i = 0; i < 6; i++)
				{
					if (Matrix.getContent(currentEntio.positionX, currentEntio.positionY - 1) == enemyEntios[i])
					{
						Matrix.modifyMap(currentEntio.positionX, currentEntio.positionY - 1, teacher.myArmy[i].tile);
					}
				}
			}
		}
	}
}

void myControl::thePlayer::moveEntio(enti::InputKey direction)
{
	int charColliderSize = Matrix.getIndex();
	bool collider = false;

	switch (direction)
	{
	case enti::InputKey::w:
	case enti::InputKey::W:
		
		for (int i = 0; i < charColliderSize; i++)
		{
			if (Matrix.getContent(currentEntio.positionX, currentEntio.positionY - 1) == Matrix.charCollider(i))
			{
				collider = true;
			}
		}
		if(collider = false) currentEntio.positionY += -1;
		break;

	case enti::InputKey::s:
	case enti::InputKey::S:

		for (int i = 0; i < charColliderSize; i++)
		{
			if (Matrix.getContent(currentEntio.positionX, currentEntio.positionY + 1) == Matrix.charCollider(i))
			{
				collider = true;
			}
		}
		if (collider = false) currentEntio.positionY += 1;
		break;

	case enti::InputKey::a:
	case enti::InputKey::A:

		for (int i = 0; i < charColliderSize; i++)
		{
			if (Matrix.getContent(currentEntio.positionX - 1, currentEntio.positionY) == Matrix.charCollider(i))
			{
				collider = true;
			}
		}
		if (collider = false) currentEntio.positionX += -1;
		break;

	case enti::InputKey::d:
	case enti::InputKey::D:

		for (int i = 0; i < charColliderSize; i++)
		{
			if (Matrix.getContent(currentEntio.positionX + 1, currentEntio.positionY) == Matrix.charCollider(i))
			{
				collider = true;
			}
		}
		if (collider = false) currentEntio.positionX += 1;
		break;

	default:
		break;
	}
}

void myControl::thePlayer::undoAction()
{

}

void myControl::thePlayer::redoAction()
{

}

void myControl::thePlayer::changeEntio()
{

}

void myControl::thePlayer::endTurn()
{

}

bool operator < (const myControl::Entio & A, const myControl::Entio & B)
{
	if (A.fatigue < B.fatigue)
		return B < A;
}
/*
bool myControl::Entio::terrainCheck(int originX, int originY, int destinyX, int destinyY, enti::InputKey direction)
{
	if (destinyX > colNum)
		destinyX = colNum;

	if (destinyX < 0)
		destinyX = 0;

	if (destinyY > rowNum)
		destinyY = rowNum;

	if (destinyY < 0)
		destinyY = 0;

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
*/