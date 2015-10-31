#include "stdafx.h"
#include "Level.h"

Level::Level(int _width, int _height, int _floor) {
	width = _width;
	height = _height;
	floor = _floor;

	DungeonGenerator g;
	dungeon = g.GenerateRooms(width, height, floor);
	
	chooseStartRoom();
	if (floor < 4) {
		chooseStairRoom();
	}
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
		//dungeon->~Array2D();
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
	setStartRoom(dungeon->get(randomX, randomY));
}

void Level::chooseStairRoom()
{
	int randomX = rnd.generateInt(0, width - 1);
	int randomY = rnd.generateInt(0, height - 1);

	//kamer mag niet rondom start kamer zijn.
	while ((randomX == startRoom->GetXPosition() || randomX == startRoom->GetXPosition() - 1 || randomX == startRoom->GetXPosition() + 1)
		&& (randomY == startRoom->GetYPosition() || randomY == startRoom->GetYPosition() - 1 || randomY == startRoom->GetYPosition() + 1)) {
		randomX = rnd.generateInt(0, width - 1);
		randomY = rnd.generateInt(0, height - 1);
	}

	//begin bij willekeurige kamer
	setStairRoom(dungeon->get(randomX, randomY));
}
