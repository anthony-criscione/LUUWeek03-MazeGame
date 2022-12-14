#pragma once
#include "PlacableActor.h"
#include "Collidable.h"

class Door : public PlacableActor
{
	// Ensure Git linked properly
public:
	Door(int x, int y, ActorColor color, ActorColor closedColor);
	virtual void Draw() override;
	virtual bool collisionAct(Collidable* othActor) override;
	virtual bool collisionGeo() { return false; }

	virtual ActorType GetType() override { return ActorType::Door;  }
	bool IsOpen() { return m_isOpen;  }
	void Open() { m_isOpen = true; }

private:
	bool m_isOpen;
	ActorColor m_closedColor;
};

