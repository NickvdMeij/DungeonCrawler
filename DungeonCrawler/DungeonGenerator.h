#pragma once
#include "Room.h"
#include "RandomInt.h"

class DungeonGenerator {
private:
	Room** rooms;
	RandomInt rnd;
public:
	DungeonGenerator();
	~DungeonGenerator();
	Room** GenerateRooms(int width, int height, int level);
	void GenerateDoorways(int width, int height);
	vector<Room*> GetAdjecentRooms(Room* room, int width, int height);
	Room generateRandomRoom(int xPos, int yPos, int level);
	//void PrintDungeon(int width, int height);
};