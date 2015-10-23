#include "stdafx.h"
#include "DungeonGenerator.h"
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <vector>

using namespace std;

DungeonGenerator::DungeonGenerator()
{
}

DungeonGenerator::~DungeonGenerator()
{
}

Room** DungeonGenerator::GenerateRooms(int width, int height, int level)
{
	rooms = new Room*[width];
	for (int x = 0; x < width; x++) {
		rooms[x] = new Room[height];
	}

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			rooms[x][y] = generateRandomRoom(x, y, level);
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

	GenerateDoorways(width, height);

	return rooms;
}

//methode heeft nog aardig wat c++ errors
void DungeonGenerator::GenerateDoorways(int width, int height)
{
	deque<Room*> queue;
	vector<Room*> visitedRooms;

	uniform_int_distribution<int> distX{ 0, width - 1 };
	uniform_int_distribution<int> distY{ 0, height - 1 };

	int randomX = distX(defaultRandomEngine);
	int randomY = distY(defaultRandomEngine);

	//begin bij willekeurige kamer
	Room* start = &rooms[randomX][randomY];
	queue.push_back(start);

	//cout << endl;
	//cout << start->GetDescripton() << endl;

	while (!queue.empty()) {
		Room* room = queue.front();
		queue.pop_front(); // haal room uit queue

		bool found = find(visitedRooms.begin(), visitedRooms.end(), room) != visitedRooms.end();
		if (!found) {
			visitedRooms.push_back(room);
		}

		for (Room* adjecent : GetAdjecentRooms(room, width, height)) {
			bool found1 = find(queue.begin(), queue.end(), adjecent) != queue.end();
			bool found2 = find(visitedRooms.begin(), visitedRooms.end(), adjecent) != visitedRooms.end();

			//Als kamer nog niet bezocht is of in queue staat
			if (!found1 /*&& !found2*/ && (visitedRooms.size() < (width*height))) {
				//als kamer rechts van huidige kamer is
				int makeDoorway = 1;
				if (found2) {
					//als kamer al bezocht is moet er toch een kans zijn dat er toch een doorway komt
					int maxRoll = (width + height) / 2; //De kans is lager des te groter de dungeon
					uniform_int_distribution<int> dist{ 0,  maxRoll - 2 };
					makeDoorway = dist(defaultRandomEngine);
				}
				if (makeDoorway == 1) {
					if (adjecent->GetXPosition() > room->GetXPosition()) {
						room->SetDoorway(Room::Direction::East, *adjecent);
						adjecent->SetDoorway(Room::Direction::West, *room);
					}
					//als kamer links van huidige kamer is
					if (adjecent->GetXPosition() < room->GetXPosition()) {
						room->SetDoorway(Room::Direction::West, *adjecent);
						adjecent->SetDoorway(Room::Direction::East, *room);
					}
					//als kamer onder de huidige kamer is
					if (adjecent->GetYPosition() > room->GetYPosition()) {
						room->SetDoorway(Room::Direction::South, *adjecent);
						adjecent->SetDoorway(Room::Direction::North, *room);
					}
					//als kamer boven de huidige kamer is
					if (adjecent->GetYPosition() < room->GetYPosition()) {
						room->SetDoorway(Room::Direction::North, *adjecent);
						adjecent->SetDoorway(Room::Direction::South, *room);
					}
				}

				//zet kamer op queue
				queue.push_back(adjecent);
			}
		}
	}

	//PrintDungeon(width, height);
}


vector<Room*> DungeonGenerator::GetAdjecentRooms(Room* room, int width, int height)
{
	vector<Room*> adjecentRooms;

	int roomX = room->GetXPosition();
	int roomY = room->GetYPosition();

	bool east = room->DoesRoomHaveDoorway(Room::Direction::East);
	bool west = room->DoesRoomHaveDoorway(Room::Direction::West);
	bool north = room->DoesRoomHaveDoorway(Room::Direction::North);
	bool south = room->DoesRoomHaveDoorway(Room::Direction::South);

	if (roomX < (width - 1) && !east) {
		adjecentRooms.push_back(&rooms[roomX + 1][roomY]);
	}
	if (roomX > 0 && !west) {
		adjecentRooms.push_back(&rooms[roomX - 1][roomY]);
	}
	if (roomY < (height - 1) && !south) {
		adjecentRooms.push_back(&rooms[roomX][roomY + 1]);
	}
	if (roomY > 0 && !north) {
		adjecentRooms.push_back(&rooms[roomX][roomY - 1]);
	}

	return adjecentRooms;
}

Room DungeonGenerator::generateRandomRoom(int xPos, int yPos, int level)
{
	Room room(xPos, yPos);

	//0 tot 2 omdat je maar 3 opties zijn per kenmerk
	uniform_int_distribution<int> dist{ 0, 2 };;

	int randomSize = dist(defaultRandomEngine);
	int randomLighting = dist(defaultRandomEngine);
	int randomFurniture = dist(defaultRandomEngine);
	int randomAtmosfeer = dist(defaultRandomEngine);

	switch (randomSize) {
	case 0:
		room.setSize(Room::Size::Small);
		break;
	case 1:
		room.setSize(Room::Size::Medium);
		break;
	case 2:
		room.setSize(Room::Size::Big);
		break;
	}

	switch (randomLighting) {
	case 0:
		room.setLighting(Room::Lighting::Candle);
		break;
	case 1:
		room.setLighting(Room::Lighting::Fireplace);
		break;
	case 2:
		room.setLighting(Room::Lighting::Torch);
		break;
	}

	switch (randomAtmosfeer) {
	case 0:
		room.setAtmosfeer(Room::Atmosfeer::Clean);
		break;
	case 1:
		room.setAtmosfeer(Room::Atmosfeer::Messy);
		break;
	case 2:
		room.setAtmosfeer(Room::Atmosfeer::Stinky);
		break;
	}

	switch (randomFurniture) {
	case 0:
		room.setFurniture(Room::Furniture::Bed);
		break;
	case 1:
		room.setFurniture(Room::Furniture::Seat);
		break;
	case 2:
		room.setFurniture(Room::Furniture::Table);
		break;
	}

	///-------TODO------------///
	//Enemies genereren afhankelijk van level

	return room;

}

//void DungeonGenerator::PrintDungeon(int width, int height)
//{
//	//tijdelijk print
//	cout << "Dungeon map: " << endl;
//
//	for (int y = 0; y < height; y++)
//	{
//		for (int x = 0; x < width; x++)
//		{
//			cout << "[]";
//			if (rooms[x][y].DoesRoomHaveDoorway(Room::Direction::East)) {
//				cout << "-";
//			}
//			else {
//				cout << " ";
//			}
//		}
//		cout << endl;
//		for (int x = 0; x < width; x++)
//		{
//			if (rooms[x][y].DoesRoomHaveDoorway(Room::Direction::South)) {
//				cout << " |";
//			}
//			else {
//				cout << "  ";
//			}
//			cout << " ";
//		}
//		cout << endl;
//	}
//}