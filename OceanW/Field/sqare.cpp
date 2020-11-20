#include "sqare.h"

void Sqare::GetIn(Citizen* citizen)
{
	if (_status == STATUS::FULL && _citizenCount > _maxCitizenCount)
		return;


	Plankton* myPlankton = dynamic_cast<Plankton*>(citizen);


	if (myPlankton && _planktonCount < _maxPlanktonCount)
		_planktonCount++;
	else
		_predatorCount++;


	for (int i = 0; i < _maxCitizenCount; i++)
		if (_sqare[i] == nullptr)
			_sqare[i] = citizen;


	_citizenCount++;


	ChangeStatus();
}

void Sqare::GetOff(Citizen* citizen)
{

	for (int i = 0; i < _maxCitizenCount; i++)
	{
		if (_sqare[i] == citizen)
			_sqare[i] = nullptr;
	}

	Plankton* myPlankton = dynamic_cast<Plankton*>(citizen);
	if (myPlankton)
		_planktonCount--;
	else
		_predatorCount--;


	_citizenCount--;


	ChangeStatus();
}

void Sqare::ChangeStatus()
{
	if (_citizenCount == 0)
		_status = STATUS::EMPTY;
	else if (_citizenCount == _maxCitizenCount)
		_status = STATUS::FULL;
	else
		_status = STATUS::EMPTY;
}
