#pragma once
#include "square.h"

class Game
{
public:

	Game(int sizeX, int sizeY, int planktonCount = 0, int predatorCount = 0) :
		_sizeX(sizeX), _sizeY(sizeY),
		_citizenCount(6)
	{

		for (int y = 0; y < _sizeY; y++)
		{
			std::vector<Square> in;
			for (int x = 0; x < _sizeX; x++)
			{
				Square sq;
				in.push_back(sq);
			}
			_map.push_back(in);
			in.clear();
		}

		Generate2();
	}

	int GetSizeX() { return _sizeX; }
	int GetSizeY() { return _sizeY; }

	bool SpawnCitizen(int citizenClass, Vector2& pos);

	auto& operator[](const int index) { return _map[index]; }

private:

	void Generate2()
	{
		srand(time(0));
		std::vector<int> f;
		Vector2 position(rand() % _sizeX, rand() % _sizeY);
		int idSize = _idList.size();

		for (int i = 0; i < _citizenCount; i++)
		{
			int randNumber = 1 + rand() % idSize;

			
			f.push_back(randNumber);

			if (!SpawnCitizen(randNumber, position))
				i--;

			position.x = rand() % _sizeX;
			position.y = rand() % _sizeY;
		}
		int a = 5;
	}


	int _sizeX, _sizeY;

	std::vector<std::vector<Square>> _map;

	std::vector<Citizen*> _citizenList;

	std::vector<int> _idList = {1, 2};

	
	int _citizenCount;

};
