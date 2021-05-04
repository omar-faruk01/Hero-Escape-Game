#pragma once
#include "Item.h"
#include "Monster.h"

class Room {
private:
	string name;
	Room* east;
	Room* west;
	Room* north;
	Room* south;
	Monster* roomMonster;
	Item* roomItem;
	bool exit;

public:
	void setName(string alpha);
	string getName() const;
	void setEastRoom(Room* x);
	void setWestRoom(Room* x);
	void setNorthRoom(Room* x);
	void setSouthRoom(Room* x);
	Room* getEastRoom() const;
	Room* getWestRoom() const;
	Room* getNorthRoom() const;
	Room* getSouthRoom() const;
	void setRoomMonster(Monster* m);
	Monster* getRoomMonster();
	void setRoomItem(Item* n);
	Item* getRoomItem();
	bool isExit();
	Room(string alpha, Room* e, Room* w, Room* s, Room* n, Monster* mon, Item* itm);
	Room(string alpha, Room* e, Room* w, Room* s, Room* n, Monster* mon);
	Room(string alpha, Room* e, Room* w, Room* s, Room* n, Item* itm);
	Room(string alpha, Room* e, Room* w, Room* s, Room* n, bool ex);
};