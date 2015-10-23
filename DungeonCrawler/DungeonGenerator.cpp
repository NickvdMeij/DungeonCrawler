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
	Array2D rooms{ width, height };

	for(int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			rooms.put(Room(i, j), i, j);
		}
	}

	//tijdelijke prints
	/*for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			cout << rooms[i][j].GetDescripton() << endl;
		}
	}*/

	GenerateDoorways();
}

//methode heeft nog aardig wat c++ errors
void DungeonGenerator::GenerateDoorways()
{
	deque<Room*> queue;
	vector<Room*> visitedRooms;

	uniform_int_distribution<int> distX{ 0, rooms.get_x_size() - 1 };
	uniform_int_distribution<int> distY{ 0, rooms.get_y_size() - 1 };

	int randomX = distX(defaultRandomEngine);
	int randomY = distY(defaultRandomEngine);

	//begin bij willekeurige kamer
	Room* start = &rooms.get(randomX, randomY);
	queue.push_back(start);

	cout << endl;
	cout << start->GetDescripton() << endl;

	while (!queue.empty()) {
		Room* room = queue.front();
		queue.pop_front(); // haal room uit queue

		bool found = find(visitedRooms.begin(), visitedRooms.end(), room) != visitedRooms.end();
		if (!found) {
			visitedRooms.push_back(room);
		}

		for (Room* adjecent : GetAdjecentRooms(room)) {
			bool found1 = find(queue.begin(), queue.end(), adjecent) != queue.end();
			bool found2 = find(visitedRooms.begin(), visitedRooms.end(), adjecent) != visitedRooms.end();

			//Als kamer nog niet bezocht is of in queue staat
			if (!found1 /*&& !found2*/ && (visitedRooms.size() < (rooms.size()))) {
				//als kamer rechts van huidige kamer is
				int makeDoorway = 1;
				if (found2) {
					//als kamer al bezocht is moet het 25% kans zijn dat er toch een doorway komt
					uniform_int_distribution<int> dist{ 0,  3 };
					makeDoorway = dist(defaultRandomEngine);
				}
				if (makeDoorway == 1) {
					if (adjecent->GetXPosition() > room->GetXPosition()) {
						room->SetDoorway(Room::Direction::East, adjecent);
						adjecent->SetDoorway(Room::Direction::West, room);
					}
					//als kamer links van huidige kamer is
					if (adjecent->GetXPosition() < room->GetXPosition()) {
						room->SetDoorway(Room::Direction::West, adjecent);
						adjecent->SetDoorway(Room::Direction::East, room);
					}
					//als kamer onder de huidige kamer is
					if (adjecent->GetYPosition() > room->GetYPosition()) {
						room->SetDoorway(Room::Direction::South, adjecent);
						adjecent->SetDoorway(Room::Direction::North, room);
					}
					//als kamer boven de huidige kamer is
					if (adjecent->GetYPosition() < room->GetYPosition()) {
						room->SetDoorway(Room::Direction::North, adjecent);
						adjecent->SetDoorway(Room::Direction::South, room);
					}
				}
				
				//zet kamer op queue
				queue.push_back(adjecent);
			}
		}
	}

	PrintDungeon();
}


vector<Room*> DungeonGenerator::GetAdjecentRooms(Room* room)
{
	vector<Room*> adjecentRooms;

	int roomX = room->GetXPosition();
	int roomY = room->GetYPosition();

	bool east = room->DoesRoomHaveDoorway(Room::Direction::East);
	bool west = room->DoesRoomHaveDoorway(Room::Direction::West);
	bool north = room->DoesRoomHaveDoorway(Room::Direction::North);
	bool south = room->DoesRoomHaveDoorway(Room::Direction::South);

	if (roomX < (rooms.get_x_size() - 1) && !east) {
		adjecentRooms.push_back(&rooms.get(roomX + 1, roomY));
	}
	if (roomX > 0 && !west) {
		adjecentRooms.push_back(&rooms.get(roomX - 1, roomY));
	}
	if (roomY < (rooms.get_y_size() - 1) && !south) {
		adjecentRooms.push_back(&rooms.get(roomX, roomY + 1));
	}
	if (roomY > 0 && !north) {
		adjecentRooms.push_back(&rooms.get(roomX, roomY - 1));
	}
	
	return adjecentRooms;
}

void DungeonGenerator::PrintDungeon()
{
	//tijdelijk print
	cout << "Dungeon map: " << endl;

	for (int i = 0; i < rooms.get_x_size(); i++)
	{
		for (int j = 0; j < rooms.get_y_size(); j++)
		{
			cout << "[]";
			if (rooms.get(j, i).DoesRoomHaveDoorway(Room::Direction::East)) {
				cout << "-";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
		for (int j = 0; j < rooms.get_y_size(); j++)
		{
			if (rooms.get(j, i).DoesRoomHaveDoorway(Room::Direction::South)) {
				cout << " |";
			}
			else {
				cout << "  ";
			}
			cout << " ";
		}
		cout << endl;
	}
}
