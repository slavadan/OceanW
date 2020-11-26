#pragma once
#include "vector2.h"
#include <list>


enum EVENT
{
	MOVE,
	DEATH, 
	SPAWN
};


class Citizen;

class IObserver
{
public:

	virtual ~IObserver() {};
	virtual void MoveUpdate(Citizen* citizen, Vector2 OldCoords) = 0;
	virtual void DeathUpdate(Citizen* citizen) = 0;
	virtual void SpawnUpdate(Citizen* citizen) = 0;

};

class ISubject
{
public:

	virtual ~ISubject() {}
	virtual void Attach(IObserver* observer) = 0;
	virtual void Detach(IObserver* observer) = 0;
	virtual void Notify(EVENT type,  Vector2 OldCoords = 0) = 0;

};

class Subject : public ISubject
{
public:
	
	void Attach(IObserver* observer) override { _observerList.push_back(observer); }
	void Detach(IObserver* observer) override { _observerList.remove(observer); }


protected:

	std::list<IObserver*> _observerList;
};