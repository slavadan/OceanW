#include "plankton.h"

void Plankton::lifeCycle()
{
	if (_healthPoints == 0)
		int death = 1;

	_healthPoints -= 5;
	RestoreActionPoints();
}

bool Plankton::reproduction()
{
	if (!HasActionPoints())
		return false;
	else
	{
		Notify(EVENT::SPAWN, 0);
		return true;
	}

}
