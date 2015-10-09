#include "stdafx.h"
#include "DungeonGenerator.h"
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <random>
using namespace std;

random_device randomDevice;
default_random_engine defaultRandomEngine{ randomDevice() };

DungeonGenerator::DungeonGenerator()
{
}

DungeonGenerator::~DungeonGenerator()
{
}

void DungeonGenerator::GenerateRooms(int width, int height)
{
	rooms = new Room*[width];
	for (int i = 0; i < width; i++) {
		rooms[i] = new Room[height];
	}

	for(int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			rooms[i][j] = Room(i, j);
		}
	}

	//tijdelijke prints
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			cout << rooms[i][j].GetDescripton() << endl;
		}
	}

	//GenerateDoorways(width, height);
}

//methode heeft nog aardig wat c++ errors
void DungeonGenerator::GenerateDoorways(int width, int height)
{
	//deque<Room> queue;
	//set<Room> visitedRooms;

	//uniform_int_distribution<int> distX{ 0, width - 1 };
	//uniform_int_distribution<int> distY{ 0, height - 1 };

	//int randomX = distX(defaultRandomEngine);
	//int randomY = distY(defaultRandomEngine);

	////begin bij willekeurige kamer
	//Room start = rooms[randomX][randomY];
	//queue.push_back(start);

	//cout << endl;
	//cout << start.GetDescripton() << endl;

	//while (!queue.empty()) {
	//	Room room = queue.front();
	//	queue.pop_front(); // haal room uit queue
	//	visitedRooms.insert(room);

	//	for (Room adjecent : GetAdjecentRooms(room, width, height)) {
	//		deque<Room>::iterator it = find(queue.begin(), queue.end(), adjecent);
	//		//Als kamer nog niet bezocht is of in queue staat
	//		if (visitedRooms.find(adjecent) != visitedRooms.end() && it != queue.end()) {
	//			//als kamer rechts van huidige kamer is
	//			if (adjecent.getXPosition > room.getXPosition) {
	//				room.SetDoorway(Room::Direction::East, adjecent);
	//				adjecent.SetDoorway(Room::Direction::West, adjecent);
	//			}
	//			//als kamer links van huidige kamer is
	//			else if (adjecent.getXPosition < room.getXPosition) {
	//				room.SetDoorway(Room::Direction::West, adjecent);
	//				adjecent.SetDoorway(Room::Direction::East, adjecent);
	//			}
	//			//als kamer onder de huidige kamer is
	//			else if (adjecent.getYPosition > room.getYPosition) {
	//				room.SetDoorway(Room::Direction::South, adjecent);
	//				adjecent.SetDoorway(Room::Direction::North, adjecent);
	//			}
	//			//als kamer boven de huidige kamer is
	//			else if (adjecent.getYPosition < room.getYPosition) {
	//				room.SetDoorway(Room::Direction::North, adjecent);
	//				adjecent.SetDoorway(Room::Direction::South, adjecent);
	//			}
	//			//zet kamer op queue
	//			queue.push_back(adjecent);
	//		}
	//	}


	//}
}

vector<Room> DungeonGenerator::GetAdjecentRooms(Room room, int width, int height)
{
	vector<Room> adjecentRooms;

	int roomX = room.getXPosition();
	int roomY = room.getYPosition();

	if (roomX < width - 1) {
		adjecentRooms.push_back(rooms[roomX + 1][roomY]);
	}
	if (roomX > 0) {
		adjecentRooms.push_back(rooms[roomX - 1][roomY]);
	}
	if (roomY < height - 1) {
		adjecentRooms.push_back(rooms[roomX][roomY + 1]);
	}
	if (roomY > 0) {
		adjecentRooms.push_back(rooms[roomX][roomY - 1]);
	}

	return adjecentRooms;
}
