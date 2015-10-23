#pragma once
#include "Array2D.h"
#include <iostream>
using namespace std;

class DungeonGenerator {
private:
	Array2D rooms;
public:
	DungeonGenerator();
	~DungeonGenerator();
	void GenerateRooms(int width, int height);
	void GenerateDoorways();
	vector<Room*> GetAdjecentRooms(Room* room);
	void PrintDungeon();
	//Room** GenerateLevel(int level, int height, int width);
};