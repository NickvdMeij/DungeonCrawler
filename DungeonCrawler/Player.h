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
	void setCurrentHealth(int i) { currentHealth = i; }
	int getCurrentHealth() { return currentHealth; }
	void setTotalHealth(int i) { totalHealth = i; }
	int getTotalHealth() { return totalHealth; }
	void setLevel(int l) { level = l; }
	int getLevel() { return level; }
	void setExperience(int e) { experience = e; }
	int getExperience() { return experience; }
	void setCurrentRoom(Room* room) { currentRoom = room; }
	Room* getCurrentRoom() { return currentRoom; }
	Inventory getInventory() { return inventory; }
	Weapon* getMainHand() { return mainHand; }
	Shield* getOffHand() { return offHand; }
	void setMainHand(Weapon* weapon) { mainHand = weapon; }
	void setOffHand(Shield* shield) { offHand = shield; }
	void Equip(Weapon* weapon);
	void Equip(Shield* shield);
	void TakeDamage(int amount);
private:
	Weapon* mainHand;
	Shield* offHand;
	string name;
	int totalHealth, currentHealth, level, experience;
	Room* currentRoom;
	Inventory inventory;
};

