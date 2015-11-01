#pragma once
#include "Item.h"
class Weapon : public Item
{
public:
	Weapon();
	~Weapon();
	int getDamage();

	void setBaseDamage(int i) {
		baseDamage = i;
	};
	int getBaseDamage() {
		return baseDamage * (5 * level);
	}

	void setLevel(int i) {
		level = i;
	}
	int getLevel() {
		return level;
	}

	void setCriticalChance(int i) {
		critChance = i;
	}
	int getCriticalChance() {
		return critChance;
	}

	void setMissChance(int i) {
		missChance = i;
	}
	int getMissChance() {
		return missChance;
	}
protected:
	int level;
	int critChance;
	int missChance;
	int baseDamage;
};

