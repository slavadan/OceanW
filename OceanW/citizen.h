#pragma once
#include "vector2.h"
#include "observer.h"
#include <list>

class Citizen: public Subject
{
public:

	enum class Direction : char
	{
		UP,
		RIGHT,
		DOWN,
		LEFT
	};

	Citizen(int maxActionPoints, const Vector2 position):
		_healthPoints(100), _actionPoints(maxActionPoints),
		_maxHealthPoints(100), _maxActionPoints(maxActionPoints),
		_position(position)
	{}

	bool Move(Direction direction);

	virtual void lifeCycle() = 0;

	bool HasActionPoints() { return _actionPoints > 0; }

	float GetHealthPoints() { return _healthPoints; }

	Vector2 GetPosition() { return _position; }

	void SetPosition(Vector2 position) { _position = position; }

	virtual int GetClassID() = 0;

	virtual bool eat()  = 0;

	void SelectCitizen(Citizen* citizen) { _selectedCitizen = citizen; }

	void Death() { Notify(EVENT::DEATH, 0); delete this; }
protected:

	void Notify(EVENT type, Vector2 OldCoords) override;

	void UpdateHealth() { _healthPoints = _maxHealthPoints; }

	void RestoreActionPoints() { _actionPoints = _maxActionPoints; }

	float _healthPoints;
	int _actionPoints;

	const int _maxHealthPoints;
	const int _maxActionPoints;

	Vector2 _position;

	Citizen* _selectedCitizen = nullptr;
};