#include "Pellet.h"
#include <iostream>

Pellet::Pellet(int x, int y, int dirX, int dirY)
	: PlacableActor(x, y)
	, m_directionX(dirX)
	, m_directionY(dirY)
{
	
}

void Pellet::Draw()
{
	std::cout << '\x07';
}

void Pellet::Update()
{
	this->SetPosition(m_pPosition->x + m_directionX, m_pPosition->y + m_directionY);
}

int Pellet::getXDir() { return m_directionX; }
int Pellet::getYDir() { return m_directionY; }