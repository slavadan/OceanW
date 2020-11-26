#pragma once 
#include "../citizen.h"
#include <vector>
#include <ctime>

class Predator : public Citizen
{
public:

	enum class Gender : int
	{
		MALE,
		FEMALE
	};

	Predator(int maxActionPoints, const Vector2 position, int maxAge, int maxHungerPoints, int bodySize, Gender sex):
		Citizen(maxActionPoints, position), _bodySize(bodySize),
		_hungerPoints(maxHungerPoints), _maxHungerPoints(maxHungerPoints),
		_age(0), _maxAge(maxAge), _sex(sex)
	{}

	Gender GetSex() { return _sex; }

	int GetAge() { return _age; }
	int GetHungerPoints() { return _hungerPoints; }

	void UpdateHungerPoints() { _hungerPoints += 3; }
	
	virtual bool reproduction(Citizen* predator) = 0;

	virtual bool eat() override;

protected:

	int _hungerPoints;
	const int _maxHungerPoints;

	int _hungerCycle = 0;
	const int _maxHungerCycle = 5;

	int _age;
	const int _maxAge;
	
	const int _bodySize;

	const Gender _sex;

	const std::vector<int> _foodID = { 1 };
};