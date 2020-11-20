#pragma once
#include "../Citizen/Predator/shark.h"
#include "../Citizen/plankton.h"
#include <vector>


class Square
{
public:

	enum class STATUS : const int
	{
		EMPTY,
		HALF,
		FULL
	};

	Square():
		_status(STATUS::EMPTY), _citizenCount(0),
		_maxCitizenCount(4), _planktonCount(0),
		_maxPlanktonCount(1), _predatorCount(0)
	{}


	int GetPlantCount() { return _planktonCount; }
	int GetPredatorCount() { return _predatorCount; }

	int GetSize() { return _maxCitizenCount; }
	int GetCitizenCount() { return _citizenCount; }

	void GetIn(Citizen* citizen);
	void GetOff(Citizen* citizen);

	STATUS GetStatus() { return _status; }


	auto& operator[](const int index)
	{
		return _sqare[index];
	}

private:

	std::vector<Citizen*> _sqare = { nullptr, nullptr, nullptr, nullptr };

	int _citizenCount;
	const int _maxCitizenCount;
	
	int _planktonCount;
	const int _maxPlanktonCount;
	
	int _predatorCount;

	STATUS _status;

	void ChangeStatus();

};

