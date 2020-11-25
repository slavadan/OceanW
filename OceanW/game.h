#pragma once
#include "Game/square.h"

class Game
{
public:

	Game(int sizeX, int sizeY, int citizenCount) :
		_sizeX(sizeX), _sizeY(sizeY),
		_citizenCount(citizenCount)
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

		Generate();
		
	}

	int GetSizeX() { return _sizeX; }
	int GetSizeY() { return _sizeY; }

	

	auto& operator[](const int index) { return _map[index]; }

private:
	
	void Generate();
	bool SpawnCitizen(int citizenClass, Vector2& pos);

	int _sizeX, _sizeY;

	std::vector<std::vector<Square>> _map;

	std::vector<Citizen*> _citizenList;

	std::vector<int> _idList = {1, 2};

	
	int _citizenCount;

};
