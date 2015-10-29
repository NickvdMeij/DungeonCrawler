#include "stdafx.h"
#include "Shield.h"
#include "RandomInt.h"


Shield::Shield()
{
}


Shield::~Shield()
{
}

int Shield::getDefence()
{
	int totalDefence = 0;

	totalDefence = baseDefence * (5 * level);	

	return totalDefence;
}

bool Shield::Block()
{
	int random = RandomInt::generateInt(0, 100);

	if (random < blockChance) {
		return true;
	}
	else {
		return false;
	}
}

