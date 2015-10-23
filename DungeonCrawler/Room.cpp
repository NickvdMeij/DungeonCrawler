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

int Room::GetXPosition()
{
	return xPosition;
}

int Room::GetYPosition()
{
	return yPosition;
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

void Room::setSize(Size s)
{
	size = s;
}

void Room::setAtmosfeer(Atmosfeer a)
{
	atmosfeer = a;
}

void Room::setLighting(Lighting l)
{
	lighting = l;
}

void Room::setFurniture(Furniture f)
{
	furniture = f;
}
