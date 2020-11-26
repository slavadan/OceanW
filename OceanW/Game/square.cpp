#include "square.h"

void Square::GetIn(Citizen* citizen)
{
	if (_status == STATUS::FULL || _citizenCount > _maxCitizenCount)
		return;

	
	
	if (citizen->GetClassID() == 1)
	{
		if (_planktonCount >= _maxPlanktonCount)
			return;
		_planktonCount++;
	}
	else
	{
		if (_predatorCount >= _maxCitizenCount)
			return;
		_predatorCount++;
	}


	for(int i = 0; i < 4; i++)
		if (_sqare[i] == nullptr)
		{
			_sqare[i] = citizen;
			_citizenCount++;
			ChangeStatus();
			return;
		}

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
