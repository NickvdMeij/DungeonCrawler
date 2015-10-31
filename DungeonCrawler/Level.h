#pragma once
#include "Array2D.h"
#include "DungeonGenerator.h"

class Level {

private:
	int width, height, floor;
	Room* startRoom;
	Room* stairRoom;
	RandomInt rnd;
public:
	Array2D* dungeon;
	Level(int width, int height, int floor);
	Level() {}
	Level(const Level& other); // copy constructor
	~Level();
	Level& operator=(const Level& other); // copy assignment
	void chooseStartRoom();
	void chooseStairRoom();
	void setStartRoom(Room* room) { startRoom = room; }
	void setStairRoom(Room* room) { stairRoom = room; }
	Room* getStartRoom() { return startRoom; }
	Room* getStairRoom() { return stairRoom; }
	int getFloor() { return floor; }
};