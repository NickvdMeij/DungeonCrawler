#pragma once
#include "Array2D.h"
#include "DungeonGenerator.h"

class Level {

private:
	int width, height, floor;
	Room* startRoom;
	Room* stairRoom;
	Room* bossRoom;
	RandomInt rnd;
public:
	Array2D* dungeon;
	Level(int width, int height, int floor);
	Level() {}
	Level(const Level& other); // copy constructor
	~Level();
	Level& operator=(const Level& other); // copy assignment
	void chooseStartRoom();
	void chooseBossRoom();
	void chooseStairRoom();
	void setStartRoom(Room* room) { startRoom = room; }
	void setStairRoom(Room* room) { stairRoom = room; }
	void setBossRoom(Room* room) { bossRoom = room; }
	Room* getBossRoom() { return bossRoom; }
	Room* getStartRoom() { return startRoom; }
	Room* getStairRoom() { return stairRoom; }
	int getFloor() { return floor; }
};