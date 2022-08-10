#pragma once
#include "Point.h"
#include "Collidable.h"

enum class ActorColor
{
	Regular = 7,
	Blue = 9,
	Green = 10,
	Red = 12,
	SolidGreen = 34,
	SolidRed = 68,
	SolidBlue = 153
};

enum class ActorType
{
	Door,
	Enemy,
	Goal,
	Key,
	Money,
	Player,
	Immobile,
};

class PlacableActor : public Collidable
{
public:
	PlacableActor(int x, int y, ActorColor color = ActorColor::Regular);
	virtual ~PlacableActor();

	int GetXPosition();
	int GetYPosition();
	int* GetXPositionPointer();
	int* GetYPositionPointer();
	void SetPosition(int x, int y);
	void setActive(bool inAct) { m_IsActive = inAct; }

	ActorColor GetColor() { return m_color; }

	void Remove() { m_IsActive = false; }
	bool IsActive() { return m_IsActive; }
	void Place(int x, int y);

	virtual ActorType GetType() = 0;
	virtual void Draw() = 0;
	virtual void Update()
	{

	}

	virtual bool collisionAct(Collidable* otherAct) = 0;
	virtual bool collisionGeo() { return false; }

protected:
	Point* m_pPosition;

	bool m_IsActive;
	ActorColor m_color;
};