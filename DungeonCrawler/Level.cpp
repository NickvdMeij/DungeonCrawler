#include "stdafx.h"
#include "Level.h"

Level::Level(int _width, int _height, int _floor) {
	width = _width;
	height = _height;
	floor = _floor;

	DungeonGenerator g;
	Room** rooms = g.GenerateRooms(width, height, floor);

	dungeon.initArray2D(width, height);
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			dungeon.put(rooms[x][y], x, y);
		}
	}

	printDungeon();
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

void Level::printDungeon()
{
	cout << "Dungeon map level "<< floor << ": " << endl;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			cout << "[]";
			if (dungeon.get(x, y).DoesRoomHaveDoorway(Room::Direction::East)) {
				cout << "-";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
		for (int x = 0; x < width; x++)
		{
			if (dungeon.get(x, y).DoesRoomHaveDoorway(Room::Direction::South)) {
				cout << " |";
			}
			else {
				cout << "  ";
			}
			cout << " ";
		}
		cout << endl;
	}
}
