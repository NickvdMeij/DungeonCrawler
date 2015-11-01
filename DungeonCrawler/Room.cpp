#include "stdafx.h"
#include "Array2D.h"
#include "RandomInt.h"
#include <iostream>
#include <sstream>
using namespace std;

Room::Room(int x, int y)
{
	xPosition = x;
	yPosition = y;
	visited = true;

	enemy = new Enemy();
	enemy->setIsAlive(false);
}

Room::Room()
{
	visited = false;

	enemy = new Enemy();
	enemy->setIsAlive(false);
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
	weightDoorways[direction] = RandomInt::generateInt(1, 10);
}

int Room::getWeigthDoorway(Direction direction)
{
	return weightDoorways[direction];
}

map<Room::Direction, Room*> Room::GetAdjecentRoomsMap()
{
	map<Room::Direction, Room*> map;
	typedef std::map<Direction, Room*>::iterator it_type;
	for (it_type iterator = adjecentRooms.begin(); iterator != adjecentRooms.end(); iterator++) {
		if (iterator->second != nullptr) {
			map[iterator->first] = iterator->second;
		}
		// iterator->second = value
	}

	return map;
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
		if (iterator->second != nullptr) {
			rooms.push_back(iterator->second);
		}
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

void Room::CollapseDoorway(Direction direction)
{
	adjecentRooms[direction] = nullptr;
}

bool Room::isDoorwayCollapsed(Direction direction)
{
	return adjecentRooms[direction] == nullptr;	
}

Room & Room::operator=(const Room & other)
{
	if (this != &other) {
		enemy = other.enemy;
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
