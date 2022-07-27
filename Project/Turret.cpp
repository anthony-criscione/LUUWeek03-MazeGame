#include "Turret.h"
#include <iostream>

Turret::Turret(int x, int y, int dirX, int dirY, int period)
	: PlacableActor(x, y)
	, m_directionX(dirX)
	, m_directionY(dirY)
	, sinceLast(period)
	, cooldown(period)
	, firable(false)
{
	switch ((1 + dirX) + (3 * (1 + dirY))) {
	  case 0:
		  outChar = '\xda';
		  break;
	  case 1:
		  outChar = '\xc2';
		  break;
	  case 2:
		  outChar = '\xbf';
		  break;
	  case 3:
		  outChar = '\xc3';
		  break;
	  case 4:
		  outChar = '+';
		  break;
	  case 5:
		  outChar = '\xb4';
		  break;
	  case 6:
		  outChar = '\xc0';
		  break;
	  case 7:
		  outChar = '\xc1';
		  break;
	  case 8:
		  outChar = '\xd9';
		  break;
	  default:
		  outChar = '?';
	}
}

void Turret::Draw()
{
	std::cout << outChar;
}

void Turret::Update()
{
	if (sinceLast == 0) {
		//sinceLast = cooldown;
		firable = true;
	}
	else --sinceLast;
}

bool Turret::canFire() { return firable; }

bool Turret::Fire(Point* outPt)
{
	if (firable && outChar != '+') {
		if (outPt != nullptr) delete outPt;
		outPt = new Point(this->m_pPosition->x, this->m_pPosition->y);
		firable = false;
		sinceLast = cooldown;
		return true;
	}
	else return false;
}

int Turret::getXFire() { return m_directionX; }
int Turret::getYFire() { return m_directionY; }