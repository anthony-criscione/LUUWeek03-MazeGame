#pragma once

class PlacableActor;

class Collidable {

public:
	
	PlacableActor *thisActor = nullptr;
	virtual bool collisionAct(Collidable* othActor) = 0;
	virtual bool collisionGeo() = 0;
};