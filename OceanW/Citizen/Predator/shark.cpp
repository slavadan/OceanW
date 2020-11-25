#include "shark.h"

void Shark::lifeCycle()
{
	if (_age == _maxAge)
		int a = 5;

	_hungerPoints--;
	_age++;
	
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


		_actionPoints--;
		return true;
	}

}
