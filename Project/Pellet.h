#pragma once
#include "PlacableActor.h"
#include "Collidable.h"

class Pellet : public PlacableActor
{
public:
	Pellet(int x, int y, int dirX = -1, int dirY = 0);

	virtual ActorType GetType() override { return ActorType::Enemy; }
	virtual void Draw() override;
	virtual void Update() override;
	int getXDir();
	int getYDir();
	void despawnPrep();
	
	virtual bool collisionAct(Collidable* othActor) override;
	virtual bool collisionGeo() override;
protected:
	
private:
	/*
	int m_movementInX;
	int m_movementInY;

	int m_currentMovementX;
	int m_currentMovementY;
	*/
	
	int m_directionX;
	int m_directionY;
};

