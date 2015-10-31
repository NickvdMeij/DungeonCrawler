#pragma once

#include <iostream>
using namespace std;

class Enemy {
private:
	string name;
	int health;
	int attack;
	int defence;
	bool alive;
public:
	Enemy();
	~Enemy();
	bool isAlive() { return alive; };
	void setIsAlive(bool a) { alive = a; };
	string getName() { return name; };
	void setName(string s) { name = s; };
	void takeDamage(int i);
	int getDamage();
	void setAttack(int i) { attack = i; };
	void setDefence(int i) { defence = i; };
	int getDefence() { return defence; };
	void setHealth(int i) { health = i; };
	int getHealth() { return health; };
	int getAttack() { return attack; };

};