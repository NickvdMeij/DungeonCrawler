#pragma once
#include "Array2D.h"
#include "DungeonGenerator.h"

class Level {

private:
	Array2D dungeon;
	int width, height, floor;
	Room startRoom;
	Room stairRoom;
	RandomInt rnd;
public:
	Level(int width, int height, int floor);
	Level() {}
	Level(const Level& other);
	~Level();
	Level& operator=(const Level& other); // copy assignment
	void chooseStartRoom();
	void setStartRoom(Room room) { startRoom = room; }
	void setStairRoom(Room room) { stairRoom = room; }
	Room getStartRoom() { return startRoom; }
	Room getStairRoom() { return stairRoom; }
	int getFloor() { return floor; }
	void printDungeon();
};