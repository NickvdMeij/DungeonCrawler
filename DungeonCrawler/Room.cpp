#include "stdafx.h"
#include "Array2D.h"

#include <iostream>
#include <sstream>
using namespace std;

Room::Room(int x, int y)
{
	xPosition = x;
	yPosition = y;
	visited = false;

	enemy = new Enemy();
	enemy->setName("TestDummy");
	enemy->setHealth(500);
	enemy->setAttack(25);
	enemy->setDefence(5);
}

Room::Room()
{
	visited = false;

	enemy = new Enemy();
	enemy->setName("TestDummy");
	enemy->setHealth(50);
	enemy->setAttack(25);
	enemy->setDefence(5);
}

Room::Room(const Room & other)
{
	//cout << "room copy constructor" << endl;
	enemy = other.enemy;
	xPosition = other.xPosition;
	yPosition = other.yPosition;
	adjecentRooms = other.adjecentRooms;
	visited = other.visited;
	lighting = other.lighting;
	size = other.size;
	atmosfeer = other.atmosfeer;
	furniture = other.furniture;
}

Room::~Room()
{
}

string Room::GetDescripton()
{
	string s = string("Room position is ") + to_string(xPosition) + ":" + to_string(yPosition);
	return s;
}

void Room::SetDoorway(Direction direction, Room* room)
{
	adjecentRooms[direction] = room;
}

Room* Room::GetAdjecentRoom(Direction direction)
{
	return adjecentRooms[direction];
}

vector<Room*> Room::GetAdjecentRooms()
{
	vector<Room*> rooms;
	typedef std::map<Direction, Room*>::iterator it_type;
	for (it_type iterator = adjecentRooms.begin(); iterator != adjecentRooms.end(); iterator++) {
		rooms.push_back(iterator->second);
		// iterator->second = value
	}

	return rooms;
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

Room & Room::operator=(const Room & other)
{
	if (this != &other) {
		xPosition = other.xPosition;
		yPosition = other.yPosition;
		size = other.size;
		lighting = other.lighting;
		atmosfeer = other.atmosfeer;
		furniture = other.furniture;
		adjecentRooms = other.adjecentRooms;
		visited = other.visited;
	}
	return *this;
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

void Room::visitRoom()
{
	visited = true;
}
