#pragma once
#include "Array2D.h"
#include "DungeonGenerator.h"

class Level {
public:
	Level(int width, int height, int floor);
	~Level();
	void setStartRoom(Room* room) { startRoom = room; }
	void setStairRoom(Room* room) { stairRoom = room; }
	Room* getStartRoom() { return startRoom; }
	Room* getStairRoom() { return stairRoom; }
	void printDungeon();
private:
	Array2D dungeon;
	int width, height, floor;
	Room* startRoom;
	Room* stairRoom;
};