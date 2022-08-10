#include "Enemy.h"
#include <iostream>
#include "Player.h"

Enemy::Enemy(int x, int y, int deltaX, int deltaY)
	: PlacableActor(x, y)
	, m_currentMovementX(0)
	, m_currentMovementY(0)
	, m_directionX(0)
	, m_directionY(0)
	, m_movementInX(deltaX)
	, m_movementInY(deltaY)
{
	InitDirection();
}

void Enemy::InitDirection()
{
	if (m_movementInX != 0)
	{
		m_directionX = 1;
	}
	if (m_movementInY != 0)
	{
		m_directionY = 1;
	}
}

void Enemy::Draw()
{
	std::cout << (char)153;
}

void Enemy::Update()
{
	if (m_movementInX != 0)
	{
		UpdateDirection(m_currentMovementX, m_directionX, m_movementInX);
	}
	if (m_movementInY != 0)
	{
		UpdateDirection(m_currentMovementY, m_directionY, m_movementInY);
	}

	this->SetPosition(m_pPosition->x + m_directionX, m_pPosition->y + m_directionY);
}

void Enemy::UpdateDirection(int& current, int& direction, int& movement)
{
	current += direction;
	if (std::abs(current) > movement)
	{
		current = movement * direction;
		direction *= -1;
	}
}

bool Enemy::collisionAct(Collidable* othActor) {
	if (othActor->thisActor->GetType() == ActorType::Enemy ||
		othActor->thisActor->GetType() == ActorType::Key ||
		othActor->thisActor->GetType() == ActorType::Goal ||
		othActor->thisActor->GetType() == ActorType::Money) return true;
	else if (othActor->thisActor->GetType() != ActorType::Player) return false; // Should do a special door check 
	else {
		this->setActive(false);
		return true;
	}
}