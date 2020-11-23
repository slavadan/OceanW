#include "square.h"

bool Square::GetIn(Citizen* citizen)
{
	if (_status == STATUS::FULL || _citizenCount > _maxCitizenCount)
		return false;

	Plankton* myPlankton = dynamic_cast<Plankton*>(citizen);
	
	if (myPlankton)
	{
		if (_planktonCount >= _maxPlanktonCount)
			return false;
		_planktonCount++;
	}
	else
	{
		_predatorCount++;
	}


	for(int i = 0; i < _maxCitizenCount; i++)
		if (_sqare[i] == nullptr)
		{
			_sqare[i] = citizen;
			break;
		}


	_citizenCount++;

	ChangeStatus();
	return true;
}

void Square::GetOff(Citizen* citizen)
{

	for (int i = 0; i < _maxCitizenCount; i++)
	{
		if (_sqare[i] == citizen)
			_sqare[i] = nullptr;
		{
			break;
		}
	}

	Plankton* myPlankton = dynamic_cast<Plankton*>(citizen);
	if (myPlankton)
		_planktonCount--;
	else
		_predatorCount--;


	_citizenCount--;


	ChangeStatus();
}

void Square::ChangeStatus()
{
	if (_citizenCount == 0)
		_status = STATUS::EMPTY;
	else if (_citizenCount == _maxCitizenCount)
		_status = STATUS::FULL;
	else
		_status = STATUS::HALF;
}
