#pragma once
#include "Item.h"
class Shield : public Item
{
public:
	Shield();
	~Shield();
	int getDefence();

	bool Block();

	void setBaseDefence(int i) {
		baseDefence = i;
	};
	int getBaseDefence() {
		return baseDefence;
	}

	void setLevel(int i) {
		level = i;
	}
	int getLevel() {
		return level;
	}

	void setBlockChance(int i) {
		blockChance = i;
	}
	int getBlockChance() {
		return blockChance;
	}

protected:
	int level;
	int blockChance;
	int baseDefence;
};

