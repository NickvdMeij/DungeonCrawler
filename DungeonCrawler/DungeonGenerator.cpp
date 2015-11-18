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

Array2D* DungeonGenerator::GenerateRooms(int width, int height, int level)
{
	Array2D* rooms = new Array2D(height, width);

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			rooms->put(generateRandomRoom(x, y, level), x, y);
		}
	}

	GenerateDoorways(rooms, width, height);

	return rooms;
}

//methode heeft nog aardig wat c++ errors
void DungeonGenerator::GenerateDoorways(Array2D* rooms, int width, int height)
{
	deque<Room*> queue;
	vector<Room*> visitedRooms;

	int randomX = RandomInt::generateInt(0, width - 1);
	int randomY = RandomInt::generateInt(0, height - 1);

	//begin bij willekeurige kamer
	Room* start = rooms->get(randomX, randomY);
	queue.push_back(start);

	while (!queue.empty()) {
		Room* room = queue.front();
		queue.pop_front(); // haal room uit queue

		bool found = find(visitedRooms.begin(), visitedRooms.end(), room) != visitedRooms.end();
		if (!found) {
			visitedRooms.push_back(room);
		}

		for (Room* adjecent : GetAdjecentRooms(rooms, room, width, height)) {
			bool found1 = find(queue.begin(), queue.end(), adjecent) != queue.end();
			bool found2 = find(visitedRooms.begin(), visitedRooms.end(), adjecent) != visitedRooms.end();

			//Als kamer nog niet bezocht is of in queue staat
			if (!found1 /*&& !found2*/ && (visitedRooms.size() < (width*height))) {
				//als kamer rechts van huidige kamer is
				int makeDoorway = 1;
				if (found2) {
					//als kamer al bezocht is moet er toch een kans zijn dat er toch een doorway komt
					int maxRoll = (width + height) / 2 - 3; //De kans is lager des te groter de dungeon
					makeDoorway = RandomInt::generateInt(0, maxRoll);
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

	queue.clear();
	visitedRooms.clear();
}


vector<Room*> DungeonGenerator::GetAdjecentRooms(Array2D* rooms, Room* room, int width, int height)
{
	vector<Room*> adjecentRooms;

	int roomX = room->GetXPosition();
	int roomY = room->GetYPosition();

	bool east = room->DoesRoomHaveDoorway(Room::Direction::East);
	bool west = room->DoesRoomHaveDoorway(Room::Direction::West);
	bool north = room->DoesRoomHaveDoorway(Room::Direction::North);
	bool south = room->DoesRoomHaveDoorway(Room::Direction::South);

	if (roomX < (width - 1) && !east) {
		adjecentRooms.push_back(rooms->get(roomX + 1, roomY));
	}
	if (roomX > 0 && !west) {
		adjecentRooms.push_back(rooms->get(roomX - 1, roomY));
	}
	if (roomY < (height - 1) && !south) {
		adjecentRooms.push_back(rooms->get(roomX, roomY + 1));
	}
	if (roomY > 0 && !north) {
		adjecentRooms.push_back(rooms->get(roomX, roomY - 1));
	}

	return adjecentRooms;
}

Room DungeonGenerator::generateRandomRoom(int xPos, int yPos, int level)
{
	Room room(xPos, yPos);

	int trapChance = 20;
	int randomTrap = RandomInt::generateInt(0, 100);

	if (trapChance > randomTrap) {
		room.setTrapped(true);
	}

	int chance = 20;
	int randomEnemy = RandomInt::generateInt(0, 100);

	if (chance > randomEnemy) {
		int low = 0;
		int high = 4;
		if (level > 0) {
			low = level - 1;
		}
		if (level < 4) {
			high = level + 1;
		}
		int nameInt = RandomInt::generateInt(low, high);
		string enemyName;

		switch (nameInt) {
		case 1:
			enemyName = "Spider";
			break;
		case 2:
			enemyName = "Skeleton";
			break;
		case 3:
			enemyName = "Scorpion";
			break;
		case 4:
			enemyName = "Ogre";
			break;
		default:
			enemyName = "Goblin";
		}

		Enemy* enemy = new Enemy();
		enemy->setIsAlive(true);
		enemy->setName(enemyName);
		enemy->setAttack(25 * level);
		enemy->setDefence(10 * level);
		enemy->setHealth(100 * level);

		room.setEnemy(enemy);
	}
	else {
		room.setEnemy(nullptr);
	}

	int randomSize = RandomInt::generateInt(0, 5);
	int randomLighting = RandomInt::generateInt(0, 8);
	int randomFurniture = RandomInt::generateInt(0, 7);
	int randomAtmosfeer = RandomInt::generateInt(0, 7);

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
	case 3:
		room.setSize(Room::Size::Enormous);
		break;
	case 4:
		room.setSize(Room::Size::Gigantic);
		break;
	case 5:
		room.setSize(Room::Size::Tiny);
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
	case 3:
		room.setLighting(Room::Lighting::Creek);
		break;
	case 4:
		room.setLighting(Room::Lighting::DiscoFever);
		break;
	case 5:
		room.setLighting(Room::Lighting::Holyball);
		break;
	case 6:
		room.setLighting(Room::Lighting::Lamp);
		break;
	case 7:
		room.setLighting(Room::Lighting::Spotlight);
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
	case 3:
		room.setAtmosfeer(Room::Atmosfeer::Romantic);
		break;
	case 4:
		room.setAtmosfeer(Room::Atmosfeer::Cloudy);
		break;
	case 5:
		room.setAtmosfeer(Room::Atmosfeer::Cosy);
		break;
	case 6:
		room.setAtmosfeer(Room::Atmosfeer::Foggy);
		break;
	case 7:
		room.setAtmosfeer(Room::Atmosfeer::Dense);
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
	case 3:
		room.setFurniture(Room::Furniture::Bench);
		break;
	case 4:
		room.setFurniture(Room::Furniture::Closet);
		break;
	case 5:
		room.setFurniture(Room::Furniture::Television);
		break;
	case 6:
		room.setFurniture(Room::Furniture::Trashcan);
		break;
	case 7:
		room.setFurniture(Room::Furniture::Lounge);
		break;
	}

	///-------TODO------------///
	//Enemies genereren afhankelijk van level

	return room;

}