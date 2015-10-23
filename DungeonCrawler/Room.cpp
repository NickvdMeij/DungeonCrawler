#include "stdafx.h"
#include "Array2D.h"

#include <iostream>
#include <sstream>
using namespace std;

Room::Room(int x, int y)
{
	xPosition = x;
	yPosition = y;
}

Room::Room()
{
}

Room::~Room()
{
}

string Room::GetDescripton()
{
	string s = string("Room position is ") + to_string(xPosition) + ":" + to_string(yPosition);
	return s;
}

vector<Enemy> Room::GetEnemies()
{
	return enemies;
}

void Room::SetDoorway(Direction direction, Room room)
{
	adjecentRooms[direction] = room;
}

Room Room::GetAdjecentRoom(Direction direction)
{
	return adjecentRooms[direction];
}

bool Room::DoesRoomHaveDoorway(Direction direction)
{
	if (adjecentRooms.size() > 0) {
		auto combi = adjecentRooms.find(direction);

		if (combi != adjecentRooms.end()) {
			return true;
		}
		return false;
	}
	return false;
}

bool Room::operator<(const Room & other)
{
	if (xPosition < other.xPosition) {
		return true;
	}
	return false;
}

bool Room::operator>(const Room & other)
{
	if (xPosition > other.xPosition) {
		return true;
	}
	return false;
}

bool Room::operator==(const Room & other)
{
	if (xPosition == other.xPosition && yPosition == other.yPosition) {
		return true;
	}
	return false;
}

bool Room::operator!=(const Room& other)
{
	if (xPosition != other.xPosition || yPosition != other.yPosition) {
		return true;
	}
	return false;
}
