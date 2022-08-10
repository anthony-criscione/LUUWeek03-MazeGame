#pragma once
#include "PlacableActor.h"
#include "Collidable.h"

class Goal : public PlacableActor
{
public:
	Goal(int x, int y);

	virtual ActorType GetType() override { return ActorType::Goal; }
	virtual void Draw() override;
	virtual bool collisionAct(Collidable* othActor) { return false; }
};

