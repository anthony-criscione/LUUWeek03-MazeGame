#include "Pellet.h"
#include <iostream>
#include "Collidable.h"

Pellet::Pellet(int x, int y, int dirX, int dirY)
	: PlacableActor(x, y)
	, m_directionX(dirX)
	, m_directionY(dirY)
{
	
}

void Pellet::Draw()
{
	std::cout << '\xf8';
}

void Pellet::Update()
{
	this->SetPosition(m_pPosition->x + m_directionX, m_pPosition->y + m_directionY);
}

int Pellet::getXDir() { return m_directionX; }
int Pellet::getYDir() { return m_directionY; }
void Pellet::despawnPrep() { this->m_IsActive = false; }

bool Pellet::collisionAct(Collidable* othActor) {
	if (othActor->thisActor->GetType() == ActorType::Key ||
		othActor->thisActor->GetType() == ActorType::Goal ||
		othActor->thisActor->GetType() == ActorType::Money) return true;
	else { 
		this->despawnPrep();
		return false;
	}
}

bool Pellet::collisionGeo() {
		this->despawnPrep();
		return false;
}