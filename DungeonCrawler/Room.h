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
	void SetDoorway(Direction direction, Room* room);
	Room GetAdjecentRoom(Direction direction);
	bool DoesRoomHaveDoorway(Direction direction);
	int GetXPosition();
	int GetYPosition();
	bool operator<(const Room& other);
	bool operator>(const Room& other);
	bool operator==(const Room& other);
	bool operator!=(const Room& other);

private:
	map<Direction, Room> adjecentRooms;
	vector<Enemy> enemies;
	int xPosition, yPosition;
};