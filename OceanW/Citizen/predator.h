#pragma once 
#include "../citizen.h"
#include <ctime>

class Predator : public Citizen
{
public:

	enum class Gender : int
	{
		MALE,
		FEMALE
	};

	Predator(float maxActionPoints, const Vector2 position, int maxAge, int maxHungerPoints, int bodySize, Gender sex):
		Citizen(maxActionPoints, position), _bodySize(bodySize),
		_hungerPoints(maxHungerPoints), _maxHungerPoints(maxHungerPoints),
		_age(0), _maxAge(maxAge), _sex(sex)
	{}

	Gender GetSex() { return _sex; }
	int GetAge() { return _age; }
	int GetHungerPoints() { return _hungerPoints; }

	virtual void eat(Citizen* citizen);
	
	Predator* reproduction(Citizen* predator);

protected:

	int _hungerPoints;
	const int _maxHungerPoints;

	int _age;
	const int _maxAge;
	
	const int _bodySize;

	const Gender _sex;
};