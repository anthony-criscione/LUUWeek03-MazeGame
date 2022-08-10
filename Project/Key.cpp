#include <iostream>
#include <windows.h>

#include "Key.h"
#include "Collidable.h"
#include "Player.h"

void Key::Draw()
{
	// Third Relink
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)m_color);

	std::cout << "+";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}

bool Key::collisionAct(Collidable* othActor) {
	return false;
	
}