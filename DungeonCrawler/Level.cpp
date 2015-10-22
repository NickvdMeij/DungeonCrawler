#include "Level.h"

Level::Level() {

}

Level::~Level() {

}

void Level::setStartRoom(Room* room)
{
	startRoom = room;
}

void Level::setStairRoom(Room* room)
{
	startRoom = room;
}

Room * Level::getStartRoom()
{
	return startRoom;
}

Room * Level::getStairRoom()
{
	return stairRoom;
}
