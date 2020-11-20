#pragma once
#include "square.h"

class Field
{
public:

	Field(int sizeX, int sizeY) :
		_sizeX(sizeX), _sizeY(sizeY)
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
		}

	}

	int GetSizeX() { return _sizeX; }
	int GetSizeY() { return _sizeY; }



	auto& operator[](const int index)
	{
		return _map[index];
	}

private:
	int _sizeX, _sizeY;

	std::vector<std::vector<Square>> _map;

};
