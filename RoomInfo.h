#pragma once
#include "Room.h"
#include <string>

class RoomInfo
{
public:
	string direction; // n e s w
	string roomName;
	Room* roomAdress; // memory address of room
};