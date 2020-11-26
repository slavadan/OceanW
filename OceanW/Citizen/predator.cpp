#include "predator.h"

bool Predator::eat()
{
	if (!HasActionPoints())
		return false;

	Vector2 tempPosition = _selectedCitizen->GetPosition();
	int citizenClassId = _selectedCitizen->GetClassID();

	bool checked = false;
	for (int i = 0; i < _foodID.size(); i++)
		if (_selectedCitizen->GetClassID() == _foodID[i])
			checked = true;
		else
			checked = false;

	if (tempPosition.x == _position.x && _position.y == tempPosition.y && checked)
	{
		for (int i = 0; i < _foodID.size(); i++)
			if (_foodID[i] == citizenClassId)
			{
				UpdateHungerPoints();
				_selectedCitizen->Death();
				_actionPoints--;
				return true;
			}
	}
	else
		return false;
}
