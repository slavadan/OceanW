#pragma once
#include "Game/square.h"

class Game: public IObserver
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
		
		std::list<Citizen*>::iterator iterator = _citizenList.begin();
		while (iterator != _citizenList.end())
		{
			(*iterator)->Attach(this);
			++iterator;
		}

	}

	int GetSizeX() { return _sizeX; }
	int GetSizeY() { return _sizeY; }
	
	void SelectSquare(int coordX, int coordY) { selectedSquare = &_map[coordY][coordX]; }
	void SelectCitizen(Square& square, int index) { 
		if (square.CheckSlot(index))
			selectedCitizen = square[index];
		else
			selectedCitizen = nullptr;
	}


	auto& operator[](const int index) { return _map[index]; }

	void EndTurn();

	Square* selectedSquare = nullptr;
	Citizen* selectedCitizen = nullptr;

private:
	
	void Generate();

	bool SpawnCitizen(int citizenClass, Vector2& pos);

	void MoveUpdate(Citizen* citizen, Vector2 OldCoords) override;
	void DeathUpdate(Citizen* citizen) override;
	void SpawnUpdate(Citizen* citizen) override;
	

	int _sizeX, _sizeY;

	std::vector<std::vector<Square>> _map;

	std::list<Citizen*> _citizenList;

	std::vector<int> _idList = {1, 2};

	

	int _citizenCount;
};
