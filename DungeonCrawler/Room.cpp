#include "stdafx.h"
#include "Room.h"

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
	/*ostringstream oss;
	oss << "Room position is " << xPosition << ":" << yPosition;
	string& s = oss.str;
	return s;*/

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

int Room::getXPosition()
{
	return xPosition;
}

int Room::getYPosition()
{
	return yPosition;
}
