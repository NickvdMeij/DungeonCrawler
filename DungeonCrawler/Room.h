#pragma once
#include "Enemy.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Room {

public:
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
	int GetXPosition();
	int GetYPosition();
	bool operator<(const Room& other);
	bool operator>(const Room& other);
	bool operator==(const Room& other);
	bool operator!=(const Room& other);

private:
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
		None
	};
	enum Atmosfeer {
		Stinky,
		Clean,
		Messy
	};
	map<Direction, Room> adjecentRooms;
	Atmosfeer atmosfeer;
	Furniture furniture;
	Lighting lighting;
	Size size;
	vector<Enemy> enemies;
	int xPosition, yPosition;
};