#pragma once
#include "Room.h"
#include "RandomInt.h"
#include "Array2d.h"

class DungeonGenerator {
private:
public:
	DungeonGenerator();
	~DungeonGenerator();
	Array2D* GenerateRooms(int width, int height, int level);
	void GenerateDoorways(Array2D* rooms, int width, int height);
	vector<Room*> GetAdjecentRooms(Array2D* rooms, Room* room, int width, int height);
	Room generateRandomRoom(int xPos, int yPos, int level);
	//void PrintDungeon(int width, int height);
};