#pragma once
#include "Room.h"
#include <iostream>
using namespace std;

class DungeonGenerator {
private:
	Room** rooms;
public:
	DungeonGenerator();
	~DungeonGenerator();
	void GenerateRooms(int width, int height);
	void GenerateDoorways(int width, int height);
	vector<Room*> GetAdjecentRooms(Room* room, int width, int height);
	void PrintDungeon(int width, int height);
	//Room** GenerateLevel(int level, int height, int width);
};