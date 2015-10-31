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
		Small
	};
	enum Lighting {
		Candle,
		Fireplace,
		Torch
	};
	enum Furniture {
		Table,
		Bed,
		Seat
	};
	enum Atmosfeer {
		Stinky,
		Clean,
		Messy
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
	vector<Enemy> GetEnemies();
	void SetDoorway(Direction direction, Room* room);
	Room* GetAdjecentRoom(Direction direction);
	vector<Room*> GetAdjecentRooms();
	bool DoesRoomHaveDoorway(Direction direction);
	int GetXPosition() { return xPosition; }
	int GetYPosition() { return yPosition; }
	void setDistance(int i) { distanceFromCurrentRoom = i; }
	int getDistance() { return distanceFromCurrentRoom; }
	void setDifficulty(int i) { difficulty = i; }
	int getDifficulty() { return difficulty; }
	Room& operator=(const Room& other);
	bool operator==(const Room& other);
	bool operator!=(const Room& other);
	void setSize(Size s) { size = s; }
	void setAtmosfeer(Atmosfeer a) { atmosfeer = a; }
	void setLighting(Lighting l) { lighting = l; }
	void setFurniture(Furniture f) { furniture = f; }
	bool isVisited() { return visited; }
	void visitRoom();

private:
	map<Direction, Room*> adjecentRooms;
	map<Direction, int> weightDoorways;
	vector<Enemy> enemies;
	int xPosition, yPosition, distanceFromCurrentRoom, difficulty;
	bool visited;
	Atmosfeer atmosfeer;
	Furniture furniture;
	Lighting lighting;
	Size size;
};