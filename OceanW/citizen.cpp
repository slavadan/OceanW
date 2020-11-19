#include "citizen.h"

void Citizen::Move(Direction direction)
{
	if (!HasActionPoints())
		return;

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
}
