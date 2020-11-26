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

	if (citizen->GetClassID() == 1)
		if (_map[pos.y][pos.x].GetPlantCount() > 1)
			return false;
	
	if (citizen->GetClassID() != 1)
		if (_map[pos.y][pos.x].GetPredatorCount() >= 4)
			return false;



	_citizenList.push_back(citizen);
	_map[pos.y][pos.x].GetIn(citizen);

}

void Game::MoveUpdate(Citizen* citizen, Vector2 OldCoords)
{
	Vector2 NowCoords = citizen->GetPosition();

	bool check = false;


	if (citizen->GetClassID() == 1)
	{
		if (_map[NowCoords.y][NowCoords.x].GetPlantCount() < 1)
		{
			check = true;
		}
		else
			citizen->SetPosition(OldCoords);
	}
	else
		if (_map[NowCoords.y][NowCoords.x].GetPredatorCount() <= 4)
			check = true;
		else
			citizen->SetPosition(OldCoords);

	if (check)
	{
		_map[NowCoords.y][NowCoords.x].GetIn(citizen);
		_map[OldCoords.y][OldCoords.x].GetOff(citizen);
	}
	
}

void Game::DeathUpdate(Citizen* citizen)
{

	Vector2 coords = citizen->GetPosition();
	_map[coords.y][coords.x].GetOff(citizen);
	_citizenList.remove(citizen);
	
}

void Game::SpawnUpdate(Citizen* citizen)
{
	Plankton* myPlankton = dynamic_cast<Plankton*>(citizen);
	Vector2 position = citizen->GetPosition();

	int citizenClassID = citizen->GetClassID();

	if (myPlankton)
	{
		if (_map[position.y][position.x + 1].GetPlantCount() == 0)
			position.x++;
		else if (_map[position.y][position.x - 1].GetPlantCount() == 0)
			position.x--;
		else if (_map[position.y - 1][position.x].GetPlantCount() == 0)
			position.y--;
		else if(_map[position.y + 1][position.x].GetPlantCount() == 0)
			position.y++;
		else if (_map[position.y + 1][position.x + 1].GetPlantCount() == 0)
		{
			position.y++;
			position.x++;
		}
		else if (_map[position.y - 1][position.x - 1].GetPlantCount() == 0)
		{
			position.y--;
			position.x--;
		}
		else if (_map[position.y - 1][position.x + 1].GetPlantCount() == 0)
		{
			position.y--;
			position.x++;
		}
		else if (_map[position.y + 1][position.x - 1].GetPlantCount() == 0)
		{
			position.y++;
			position.x--;
		}
	}
	else
	{
		if (_map[position.y][position.x].GetCitizenCount() < 4)
		{
			SpawnCitizen(citizen->GetClassID(), position);
			return;
		}
		else if (_map[position.y][position.x + 1].GetCitizenCount() < 4)
			position.x++;
		else if (_map[position.y][position.x - 1].GetCitizenCount() < 4)
			position.x--;
		else if (_map[position.y - 1][position.x].GetCitizenCount() < 4)
			position.y--;
		else if (_map[position.y + 1][position.x].GetCitizenCount() < 4)
			position.y++;
		else if (_map[position.y + 1][position.x + 1].GetCitizenCount() < 4)
		{
			position.y++;
			position.x++;
		}
		else if (_map[position.y - 1][position.x - 1].GetCitizenCount() < 4)
		{
			position.y--;
			position.x--;
		}
		else if (_map[position.y - 1][position.x + 1].GetCitizenCount() < 4)
		{
			position.y--;
			position.x++;
		}
		else if (_map[position.y + 1][position.x - 1].GetCitizenCount() < 4)
		{
			position.y++;
			position.x--;
		}
	}
	SpawnCitizen(citizenClassID, position);
}

void Game::EndTurn()
{
	std::list<Citizen*>::iterator iterator = _citizenList.begin();

	while (iterator != _citizenList.end())
	{
		(*iterator)->lifeCycle();
		iterator++;
	}
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
