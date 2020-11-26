#include "shark.h"

void Shark::lifeCycle()
{
	if (_age >= _maxAge || _hungerCycle >= _maxHungerCycle)
		Death();

	_hungerPoints--;
	_age++;

	if (_hungerPoints <= 0)
	{
		_hungerPoints = 0;
		_hungerCycle++;
	}
	
	RestoreActionPoints();
}

bool Shark::eat(Citizen* citizen)
{
	if (!HasActionPoints())
		return false;

	Vector2 tempPosition = citizen->GetPosition();
	int citizenClassId = citizen->GetClassID();

	if(tempPosition.x == _position.x && _position.y == tempPosition.y)

	for(int i = 0; i < _foodID.size(); i++)
		if (_foodID[i] == citizenClassId)
		{
			UpdateHungerPoints();
			citizen->Death();
			_actionPoints--;
			return true;
		}
	
}

bool Shark::reproduction(Citizen* predator)
{
	Predator* myPredator = dynamic_cast<Predator*>(predator);
	Vector2 tempPos = predator->GetPosition();

	if (!myPredator || !HasActionPoints())
		return false;

	int predatorClassID = predator->GetClassID();
	int thisPredatorClassID = GetClassID();


	if (predatorClassID != thisPredatorClassID || _sex == myPredator->GetSex() || tempPos.x != _position.x || tempPos.y != tempPos.y)
		return false;
	else
	{
		Notify(EVENT::SPAWN, 0);
		_actionPoints--;
		return true;
	}

}
