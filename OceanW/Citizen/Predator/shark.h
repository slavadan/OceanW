#pragma once
#include "../predator.h"

class Shark : public Predator
{
public:

	Shark(const Vector2 position, Gender sex):
		Predator(2, position, 50, 8, 2, sex)
	{
		
	}

	void lifeCycle() override;
	
	int GetClassID() override { return id; }

	bool reproduction(Citizen* predator) override;

private:

	static const int id = 2;
};
