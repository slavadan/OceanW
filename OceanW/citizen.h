#pragma once
#include "vector2.h"

class Citizen
{
public:

	enum class Direction : char
	{
		UP,
		RIGHT,
		DOWN,
		LEFT
	};

	Citizen(int maxActionPoints):
		_healthPoints(100), _actionPoints(maxActionPoints),
		_maxHealthPoints(100), _maxActionPoints(maxActionPoints)
	{}

	void move(Direction direction);
	void RestoreActionPoints() { _actionPoints = _maxActionPoints; }

	virtual void lifeCycle() = 0;

	bool HasActionPoints() { return _actionPoints > 0; }

	float GetHealthPoints() { return _healthPoints; }
	Vector2 GetPosition() { return _position; }

protected:

	float _healthPoints;
	int _actionPoints;

	const int _maxHealthPoints;
	const int _maxActionPoints;

	Vector2 _position;
};