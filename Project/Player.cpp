#include <iostream>

#include "Player.h"
#include "Key.h"
#include "AudioManager.h"
#include "Money.h"
#include "Enemy.h"
#include "Goal.h"
#include "Door.h"
#include "Pellet.h"

using namespace std;

constexpr int kStartingNumberOfLives = 3;

Player::Player()
	: PlacableActor(0, 0)
	, m_pCurrentKey(nullptr)
	, m_money(0)
	, m_lives(kStartingNumberOfLives)
	, hasWon(false)
{

}

bool Player::HasKey()
{
	return m_pCurrentKey != nullptr;
}

bool Player::HasKey(ActorColor color)
{
	return true;// HasKey() && m_pCurrentKey->GetColor() == color;
}

void Player::PickupKey(Key* key)
{
	m_pCurrentKey = key;
}

void Player::UseKey()
{
	if (m_pCurrentKey)
	{
		m_pCurrentKey->Remove();
		m_pCurrentKey = nullptr;
	}
}

void Player::DropKey()
{
	if (m_pCurrentKey)
	{
		AudioManager::GetInstance()->PlayKeyDropSound();
		m_pCurrentKey->Place(m_pPosition->x, m_pPosition->y);
		m_pCurrentKey = nullptr;
	}
}

void Player::Draw()
{
	cout << "@";
}

bool Player::collisionAct(Collidable* othActor) {

	switch (othActor->thisActor->GetType()) {
	case ActorType::Door: {
		Door* collidedDoor = dynamic_cast<Door*>(othActor);
		if (!collidedDoor->IsOpen())
		{
			if (this->HasKey(collidedDoor->GetColor()))
			{
				collidedDoor->Open();
				collidedDoor->Remove();
				this->UseKey();
				AudioManager::GetInstance()->PlayDoorOpenSound();
				return true;
			}
			else
			{
				AudioManager::GetInstance()->PlayDoorClosedSound();
				return false;
			}
		}
		else
		{
			return true;
		}
		break;
	}
	case ActorType::Enemy: {
		if (dynamic_cast<Enemy*>(othActor) != nullptr) {
			Enemy* collidedEnemy = dynamic_cast<Enemy*>(othActor);
			AudioManager::GetInstance()->PlayLoseLivesSound();
			collidedEnemy->Remove();
		}
		else if (dynamic_cast<Pellet*>(othActor) != nullptr) {
			Pellet* collidedEnemy = dynamic_cast<Pellet*>(othActor);
			AudioManager::GetInstance()->PlayLoseLivesSound();
			collidedEnemy->Remove();
		}
		this->DecrementLives();
		return true;
		break;
	}
	case ActorType::Goal: {
		Goal* collidedGoal = dynamic_cast<Goal*>(othActor);
		collidedGoal->Remove();
		this->hasWon = true;
		//thisGame->beatLevel();
		return true;
		break;
	}
	case ActorType::Key: {
		if (not this->HasKey()) this->PickupKey(dynamic_cast<Key*>(othActor));
		dynamic_cast<Key*>(othActor)->Remove();
		return true;
		break;
	}
	case ActorType::Money: {
		AudioManager::GetInstance()->PlayMoneySound();
		this->AddMoney(dynamic_cast<Money*>(othActor)->GetWorth());
		dynamic_cast<Money*>(othActor)->Remove();
		return true;
		break;
	}
	case ActorType::Immobile: {
		return false;
		break;
	}
	default: {
		// Unhandled collision
		return false;
	}
	}
}
