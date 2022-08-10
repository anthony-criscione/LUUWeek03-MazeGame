#pragma once
#include "PlacableActor.h"
#include "Collidable.h"
class Key : public PlacableActor
{
public:
	Key(int x, int y, ActorColor color)
		: PlacableActor(x, y, color)
	{

	}

	virtual ActorType GetType() override { return ActorType::Key; }
	virtual void Draw() override;
	virtual bool collisionAct(Collidable* othActor) override;
};

