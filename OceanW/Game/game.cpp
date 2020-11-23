#include "game.h"

bool Game::SpawnCitizen(int citizenClass, Vector2& pos)
{

	Citizen* citizen = nullptr;
	Predator::Gender sex;


	int randNumber = rand() % 2;
	if (randNumber == 0)
		sex = Predator::Gender::MALE;
	else
		sex = Predator::Gender::FEMALE;

	if (citizenClass == 1)
		citizen = new Plankton(pos);
	else if (citizenClass == 2)
		citizen = new Shark(pos, sex);
	else
	{
		delete citizen;
		return false;
	}

	if (_map[pos.y][pos.x].GetIn(citizen))
	{
		_citizenList.push_back(citizen);
	}
	else
		return false;

}
