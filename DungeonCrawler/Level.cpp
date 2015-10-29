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
	chooseStartRoom();
}

Level::Level(const Level & other)
{
	startRoom = other.startRoom;
	stairRoom = other.stairRoom;
	floor = other.floor;
	width = other.width;
	height = other.height;
	dungeon = other.dungeon;
}

Level::~Level() {
	//startRoom = nullptr;
	//stairRoom = nullptr;
}

Level& Level::operator=(const Level & other)
{
	if (this != &other) {
		//delete startRoom;
		//delete stairRoom;
		//startRoom = nullptr;
		//stairRoom = nullptr;
		dungeon.~Array2D();
		startRoom = other.startRoom;
		stairRoom = other.stairRoom;
		floor = other.floor;
		width = other.width;
		height = other.height;
		dungeon = other.dungeon;
	}
	return *this;
}

void Level::chooseStartRoom()
{
	int randomX = rnd.generateInt(0, width - 1);
	int randomY = rnd.generateInt(0, height - 1);

	//begin bij willekeurige kamer
	setStartRoom(dungeon.get(randomX, randomY));
}

void Level::printDungeon()
{
	cout << "Dungeon map level "<< floor << ": " << endl;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (dungeon.get(x, y).isVisited()) {
				cout << "N";
				if (dungeon.get(x, y).DoesRoomHaveDoorway(Room::Direction::East)) {
					cout << "-";
				}
				else {
					cout << " ";
				}
			}
			else {
				cout << ".";
				cout << " ";
			}
		}
		cout << endl;
		for (int x = 0; x < width; x++)
		{
			if (dungeon.get(x, y).isVisited()) {
				if (dungeon.get(x, y).DoesRoomHaveDoorway(Room::Direction::South)) {
					cout << "|";
				}
				else {
					cout << " ";
				}
			}
			else {
				cout << " ";
			}
			cout << " ";
		}
		cout << endl;
	}
}
