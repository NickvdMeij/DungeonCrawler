#pragma once
#include "Room.h"
#include <random>
using namespace std;

class DungeonGenerator {
private:
	Room** rooms;
	random_device randomDevice;
	default_random_engine defaultRandomEngine{ randomDevice() };
public:
	DungeonGenerator();
	~DungeonGenerator();
	Room** GenerateRooms(int width, int height, int level);
	void GenerateDoorways(int width, int height);
	vector<Room*> GetAdjecentRooms(Room* room, int width, int height);
	Room generateRandomRoom(int xPos, int yPos, int level);
	//void PrintDungeon(int width, int height);
};