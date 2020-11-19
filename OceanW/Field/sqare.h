#pragma once
#include "../Citizen/Predator/shark.h"
#include "../Citizen/plankton.h"
#include <vector>

class Sqare
{
public:

	enum class Status : char
	{
		EMPTY,
		HALF,
		FULL
	};

	Sqare():
		_status(Status::EMPTY), _citizenCount(0),
		_maxCitizenCount(4), _plantCount(0),
		_maxPlantCount(1), _predatorCount(0),
		_size(0), _maxSize(4)
	{}


	int GetPlantCount() { return _plantCount; }
	int GetPredatorCount() { return _predatorCount; }

	int GetSize() { return _size; }
	int GetCitizen_count() { return _citizenCount; }

	void GetIn(Citizen* citizen);
	void GetOff(Citizen* citizen);

	Vector2 GetCoods() { return _coords; }


	auto& operator[](const int index)
	{
		return sqare[index];
	}

private:
	std::vector<Citizen*> sqare = { nullptr, nullptr, nullptr, nullptr };

	int _citizenCount;
	const int _maxCitizenCount;
	
	int _plantCount;
	int _maxPlantCount;
	
	int _predatorCount;

	int _size, _maxSize;
	
	Vector2 _coords;
	Status _status;
};

