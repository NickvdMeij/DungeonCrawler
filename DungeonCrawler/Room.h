#pragma once
#include "Enemy.h"
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
		None
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
	int GetXPosition();
	int GetYPosition();
	bool operator<(const Room& other);
	bool operator>(const Room& other);
	bool operator==(const Room& other);
	bool operator!=(const Room& other);
	void setSize(Size s);
	void setAtmosfeer(Atmosfeer a);
	void setLighting(Lighting l );
	void setFurniture(Furniture f);

private:
	map<Direction, Room> adjecentRooms;
	vector<Enemy> enemies;
	int xPosition, yPosition;
	Atmosfeer atmosfeer;
	Furniture furniture;
	Lighting lighting;
	Size size;
};