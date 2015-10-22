#pragma once
#include "Array2D.h"

class Level {
public:
	Level();
	~Level();
	void setStartRoom(Room* room);
	void setStairRoom(Room* room);
	Room* getStartRoom();
	Room* getStairRoom();
private:
	
	Room* startRoom;
	Room* stairRoom;
};