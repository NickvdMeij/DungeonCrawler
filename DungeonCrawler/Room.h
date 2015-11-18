#pragma once
#include "Enemy.h"
#include "Item.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Room {

public:
	enum Size {
		Big,
		Medium,
		Small,
		Enormous,
		Tiny,
		Gigantic
	};
	enum Lighting {
		Candle,
		Fireplace,
		Torch,
		DiscoFever,
		Window,
		Creek,
		Lamp,
		Holyball,
		Spotlight
	};
	enum Furniture {
		Table,
		Bed,
		Seat,
		Closet,
		Bench,
		Lounge,
		Television,
		Trashcan
	};
	enum Atmosfeer {
		Stinky,
		Clean,
		Messy,
		Foggy,
		Dense,
		Cloudy,
		Romantic,
		Cosy
	};
	enum Direction {
		North,
		East,
		South,
		West
	};
	Room(int x, int y);
	Room();
	Room(const Room& other); // copy constructor
	~Room();
	string GetDescripton();
	void SetDoorway(Direction direction, Room* room);
	int getWeigthDoorway(Direction direction);
	map<Room::Direction, Room*> GetAdjecentRoomsMap();
	Room* GetAdjecentRoom(Direction direction);
	vector<Room*> GetAdjecentRooms();
	bool DoesRoomHaveDoorway(Direction direction);
	void CollapseDoorway(Direction direction);
	bool isDoorwayCollapsed(Direction direction);
	void removeEnemy();
	int GetXPosition() { return xPosition; }
	int GetYPosition() { return yPosition; }
	void setDistance(int i) { distanceFromCurrentRoom = i; }
	int getDistance() { return distanceFromCurrentRoom; }
	void setDifficulty(int i) { difficulty = i; }
	int getDifficulty() { return difficulty; }
	Room& operator=(const Room& other); // copy assignment
	bool operator==(const Room& other);
	bool operator!=(const Room& other);
	void setSize(Size s) { size = s; }
	void setAtmosfeer(Atmosfeer a) { atmosfeer = a; }
	void setLighting(Lighting l) { lighting = l; }
	void setFurniture(Furniture f) { furniture = f; }
	bool isVisited() { return visited; }
	void visitRoom();
	bool hasEnemy() { 
		if (enemy == nullptr) { return false; }
		return enemy->isAlive();
	};
	Enemy* getEnemy() {
		return enemy;
	};
	void setEnemy(Enemy* e) {
		enemy = e;
	}

private:
	Enemy* enemy;
	map<Direction, Room*> adjecentRooms;
	map<Direction, int> weightDoorways;
	int xPosition, yPosition, distanceFromCurrentRoom, difficulty;
	bool visited;
	Atmosfeer atmosfeer;
	Furniture furniture;
	Lighting lighting;
	Size size;
};