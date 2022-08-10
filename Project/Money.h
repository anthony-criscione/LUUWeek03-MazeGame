#pragma once
#include "PlacableActor.h"
#include "Collidable.h"

class Money : public PlacableActor
{
public:
	Money(int x, int y, int worth);

	int GetWorth() const { return m_worth; }

	virtual ActorType GetType() override { return ActorType::Money; }
	virtual void Draw() override;

	virtual bool collisionAct(Collidable* othActor) { return false; }
	

private:
	int m_worth;
};

