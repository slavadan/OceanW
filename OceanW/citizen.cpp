#include "citizen.h"

bool Citizen::Move(Direction direction)
{
	if (!HasActionPoints())
		return false;

	switch (direction)
	{
	case Direction::UP:
		_position.y += 1;
		break;

	case Direction::DOWN:
		_position.y -= 1;
		break;

	case Direction::LEFT:
		_position.x -= 1;
		break;

	case Direction::RIGHT:
		_position.x += 1;
		break;
	}

	_actionPoints--;
	//Notify(EVENT::MOVE, this);
	return true;
	
}