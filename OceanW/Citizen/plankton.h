#pragma once
#include "../citizen.h"

class Plankton : public Citizen
{
public:

	Plankton(const Vector2 position = 0):
		Citizen(1, position)
	{}

	void lifeCycle() override;

	bool reproduction();

	int GetClassID() override { return id; }

private:

	static const int id = 1;

};