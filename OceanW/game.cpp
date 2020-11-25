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

	Plankton* myPlankton = dynamic_cast<Plankton*>(citizen);

	if (_map[pos.y][pos.x].GetIn(citizen))
	{
		_citizenList.push_back(citizen);
	}
	else
		return false;

}

void Game::Generate()
{
	srand(time(0));

	Vector2 position(rand() % _sizeX, rand() % _sizeY);
	int idSize = _idList.size();
	int randNumber = 0;


	for (int i = 0; i < _citizenCount; i++)
	{
		randNumber = 1 + rand() % idSize;

		if (!SpawnCitizen(randNumber, position))
			i--;

		position.x = rand() % _sizeX;
		position.y = rand() % _sizeY;
	}
}
