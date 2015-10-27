#pragma once
#include "Room.h"
#include "Inventory.h"
#include <iostream>
using namespace std;

class Player
{
public:
	Player();
	~Player();
	void MoveDirection(Room::Direction direction);

	void setName(string n) { name = n; }
	string getName() { return name; }
	void setHealthPoints(int i) { healthpoints = i; }
	int getHealthPoints() { return healthpoints; }
	void setLevel(int l) { level = l; }
	int getLevel() { return level; }
	void setExperience(int e) { experience = e; }
	int getExperience() { return experience; }
	void setAttack(int a) { attack = a; }
	int getAttack() { return attack; }
	void setDefence(int d) { defence = d; }
	int getDefence() { return defence; }
	void setPerception(int p) { perception = p; }
	int getPerception() { return perception; }
	void setCurrentRoom(Room room) { currentRoom = room; }
	Room getCurrentRoom() { return currentRoom; }
private:
	string name;
	Room currentRoom;
	int healthpoints, level, experience, attack, defence, perception;
	Inventory inventory;
};

