#include "citizen.h"

bool Citizen::Move(Direction direction)
{
	if (!HasActionPoints())
		return false;

	Vector2 oldCoords = this->GetPosition();

	switch (direction)
	{
	case Direction::UP:
		_position.y -= 1;
		break;

	case Direction::DOWN:
		_position.y += 1;
		break;

	case Direction::LEFT:
		_position.x -= 1;
		break;

	case Direction::RIGHT:
		_position.x += 1;
		break;
	}

	_actionPoints--;
	Notify(EVENT::MOVE, oldCoords);
	return true;
	
}

void Citizen::Notify(EVENT type, Vector2 OldCoords)
{
	std::list<IObserver*>::iterator iterator = _observerList.begin();

	switch (type)
	{
	case EVENT::MOVE:
		while (iterator != _observerList.end())
		{
			(*iterator)->MoveUpdate(this, OldCoords);
			iterator++;
		}
	break;

	case EVENT::DEATH:
		while (iterator != _observerList.end())
		{
			(*iterator)->DeathUpdate(this);
			iterator++;
		}

	case EVENT::SPAWN:
		while (iterator != _observerList.end())
		{
			(*iterator)->SpawnUpdate(this);
			iterator++;
		}
	}
}
