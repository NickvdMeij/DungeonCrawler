#pragma once
#include "Room.h"
#include "RandomInt.h"
#include "Array2d.h"

class DungeonGenerator {
private:
	Array2D* rooms;
	RandomInt rnd;
public:
	DungeonGenerator();
	~DungeonGenerator();
	Array2D* GenerateRooms(int width, int height, int level);
	void GenerateDoorways(int width, int height);
	vector<Room*> GetAdjecentRooms(Room* room, int width, int height);
	Room generateRandomRoom(int xPos, int yPos, int level);
	//void PrintDungeon(int width, int height);
};