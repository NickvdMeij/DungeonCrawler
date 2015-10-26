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
	~Room();
	string GetDescripton();
	vector<Enemy> GetEnemies();
	void SetDoorway(Direction direction, Room room);
	Room GetAdjecentRoom(Direction direction);
	bool DoesRoomHaveDoorway(Direction direction);
	int GetXPosition() { return xPosition; }
	int GetYPosition() { return yPosition; }
	Room& operator=(const Room& other);
	bool operator==(const Room& other);
	bool operator!=(const Room& other);
	void setSize(Size s) { size = s; }
	void setAtmosfeer(Atmosfeer a) { atmosfeer = a; }
	void setLighting(Lighting l) { lighting = l; }
	void setFurniture(Furniture f) { furniture = f; }
	bool isVisited() { return visited; }
	void visitRoom() { visited = true; }

private:
	map<Direction, Room> adjecentRooms;
	vector<Enemy> enemies;
	int xPosition, yPosition;
	bool visited;
	Atmosfeer atmosfeer;
	Furniture furniture;
	Lighting lighting;
	Size size;
};