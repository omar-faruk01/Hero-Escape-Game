#include "Room.h"

void Room::setName(string alpha)
{
	name = alpha;
}

string Room::getName() const
{
	return name;
}

void Room::setEastRoom(Room* x)
{
	east = x;
}

void Room::setWestRoom(Room* x)
{
	west = x;
}

void Room::setNorthRoom(Room* x)
{
	north = x;
}

void Room::setSouthRoom(Room* x)
{
	south = x;
}

Room* Room::getEastRoom() const
{
	return east;;
}

Room* Room::getWestRoom() const
{
	return west;
}

Room* Room::getNorthRoom() const
{
	return north;
}

Room* Room::getSouthRoom() const
{
	return south;
}

void Room::setRoomMonster(Monster* m)
{
	roomMonster = m;
}

Monster* Room::getRoomMonster()
{
	return roomMonster;
}

void Room::setRoomItem(Item* n)
{
	roomItem = n;
}

Item* Room::getRoomItem()
{
	return roomItem;
}

bool Room::isExit()
{
	return exit;
}

Room::Room(string alpha, Room* e, Room* w, Room* s, Room* n, Monster* mon, Item* itm) : Room(alpha, e, w, s, n, false)
{
	roomMonster = mon;
	roomItem = itm;
}

Room::Room(string alpha, Room* e, Room* w, Room* s, Room* n, Monster* mon) : Room(alpha, e, w, s, n, false)
{
	roomMonster = mon;
	roomItem = nullptr;
}

Room::Room(string alpha, Room* e, Room* w, Room* s, Room* n, Item* itm) : Room(alpha, e, w, s, n, false)
{
	roomMonster = nullptr;
	roomItem = itm;
}

Room::Room(string alpha, Room* e, Room* w, Room* s, Room* n, bool ex)
{
	name = alpha;
	exit = ex;
	east = e;
	west = w;
	north = n;
	south = s;
}