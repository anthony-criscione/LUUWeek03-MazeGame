#include <iostream>
#include <windows.h>
#include "Door.h"
#include "Player.h"

Door::Door(int x, int y, ActorColor color, ActorColor closedColor)
	: PlacableActor(x, y, color)
	, m_isOpen(false)
	, m_closedColor(closedColor)
{

}

void Door::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (m_isOpen)
	{
		SetConsoleTextAttribute(console, (int)m_color);
	}
	else
	{
		SetConsoleTextAttribute(console, (int)m_closedColor);
	}
	std::cout << "|";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}

bool Door::collisionAct(Collidable* othActor) {
	if (othActor->thisActor->GetType() != ActorType::Player) return false;
	else {
		/*Player* tmpPlayer = dynamic_cast<Player*>(othActor->thisActor);
		if (tmpPlayer->HasKey()) {
			this->Open();
		}*/
		return false;
	}
}