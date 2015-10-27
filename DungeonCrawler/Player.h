#pragma once
#include "Room.h"
#include "Inventory.h"
#include <iostream>
#include "Weapon.h"
#include "Shield.h"

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
	Inventory getInventory() { return inventory; }
	Weapon getMainHand() { return mainHand; }
	Shield getOffHand() { return offHand; }
	void setMainHand(Weapon weapon) { mainHand = weapon; }
	void setOffHand(Shield shield) { offHand = shield; }
	void Equip(Weapon weapon);
	void Equip(Shield shield);
private:
	Weapon mainHand;
	Shield offHand;
	string name;
	Room currentRoom;
	int healthpoints, level, experience, attack, defence, perception;
	Inventory inventory;
};

