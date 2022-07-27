#pragma once
#include "PlacableActor.h"
class Turret : public PlacableActor
{
public:
	Turret(int x, int y, int dirX = 1, int dirY = 0, int period = 4);

	virtual ActorType GetType() override { return ActorType::Immobile; }
	virtual void Draw() override;
	virtual void Update() override;
	bool canFire();
	bool Fire(Point* outPt);
	int getXFire();
	int getYFire();


protected:
	//void InitDirection();

private:
	//int m_movementInX;
	//int m_movementInY;

	//int m_currentMovementX;
	//int m_currentMovementY;

	int m_directionX;
	int m_directionY;

	int sinceLast;
	int cooldown;

	char outChar;
	bool firable;

};

