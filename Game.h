#pragma once

#include "Character.h"
#include "Item.h"
#include "Monster.h"
#include "Room.h"
#include "Hero.h"

class Game {
public:
	Hero HeroName;
	void run();
	Game();

private:
	void createMap();
	Room* currentRoom;
	Room* previousRoom;
};