#pragma once
#include "Array2D.h"
#include "DungeonGenerator.h"

class Level {
public:
	Level(int width, int height, int floor);
	~Level();
	void setStartRoom(Room* room);
	void setStairRoom(Room* room);
	Room* getStartRoom();
	Room* getStairRoom();
	void printDungeon();
private:
	Array2D dungeon;
	int width, height, floor;
	Room* startRoom;
	Room* stairRoom;
};