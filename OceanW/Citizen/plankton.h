#pragma once
#include "../citizen.h"

class Plankton : public Citizen
{
public:

	Plankton(const Vector2 position = 0):
		Citizen(1, position)
	{}

	void lifeCycle() override {}


private:

	const int id = 1;

};