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
	visited = false;

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
	delete enemy;
	enemy = nullptr;
	//adjecentRooms.clear();
}

string Room::GetDescripton()
{
	string atm = "";
	string sz = "";
	string light = "";
	string fur = "";

	switch (furniture) {
	case Room::Furniture::Bed:
		fur = "bed";
		break;
	case Room::Furniture::Bench:
		fur = "bench";
		break;
	case Room::Furniture::Closet:
		fur = "closet";
		break;
	case Room::Furniture::Lounge:
		fur = "lounge";
		break;
	case Room::Furniture::Seat:
		fur = "seat";
		break;
	case Room::Furniture::Table:
		fur = "table";
		break;
	case Room::Furniture::Television:
		fur = "television";
		break;
	case Room::Furniture::Trashcan:
		fur = "trash can";
		break;
	}

	switch (lighting) {
	case Room::Lighting::Candle:
		light = "candle light";
		break;
	case Room::Lighting::Creek:
		light = "creek";
		break;
	case Room::Lighting::DiscoFever:
		light = "fancy disco lights";
		break;
	case Room::Lighting::Fireplace:
		light = "large fire pit";
		break;
	case Room::Lighting::Holyball:
		light = "holy ballzzz";
		break;
	case Room::Lighting::Lamp:
		light = "simple lamp";
		break;
	case Room::Lighting::Spotlight:
		light = "huge spotlight";
		break;
	case Room::Lighting::Torch:
		light = "torch";
		break;
	case Room::Lighting::Window:
		light = "window (in a dungeon?....)";
		break;
	}

	switch (atmosfeer) {
	case Room::Atmosfeer::Clean:
		atm = "clean";
		break;
	case Room::Atmosfeer::Cloudy:
		atm = "cloudy";
		break;
	case Room::Atmosfeer::Cosy:
		atm = "cosy";
		break;
	case Room::Atmosfeer::Dense:
		atm = "dense";
		break;
	case Room::Atmosfeer::Foggy:
		atm = "foggy";
		break;
	case Room::Atmosfeer::Messy:
		atm = "messy";
		break;
	case Room::Atmosfeer::Romantic:
		atm = "romantic";
		break;
	case Room::Atmosfeer::Stinky:
		atm = "stinky";
		break;
	}

	switch (size) {
		case Room::Size::Big:
			sz = "big";
			break;
		case Room::Size::Enormous:
			sz = "enourmous";
			break;
		case Room::Size::Gigantic:
			sz = "gigantic";
			break;
		case Room::Size::Medium:
			sz = "medium";
			break;
		case Room::Size::Small:
			sz = "small";
			break;
		case Room::Size::Tiny:
			sz = "tiny";
			break;
	}


	string s = "This room is " + atm + ", because the room is " + sz + " and illuminated by a " + light + ", the " + fur + " is properly visible";
	return s;
}

void Room::SetDoorway(Direction direction, Room* room)
{
	adjecentRooms[direction] = room;
	if (hasEnemy()) {
		weightDoorways[direction] = 2;
	}
	else {
		weightDoorways[direction] = 1;
	}
	
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
