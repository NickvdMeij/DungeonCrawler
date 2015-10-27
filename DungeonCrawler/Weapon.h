#pragma once
#include "Item.h"
class Weapon : public Item
{
public:
	Weapon();
	~Weapon();
	int getDamage() { return damage; }
	void setDamage(int i) { damage = i; }
protected:
	int damage;
};

