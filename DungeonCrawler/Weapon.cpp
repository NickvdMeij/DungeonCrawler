#include "stdafx.h"
#include "Weapon.h"
#include "RandomInt.h"


Weapon::Weapon()
{
}


Weapon::~Weapon()
{
}

int Weapon::getDamage()
{
	int totalDamage;

	totalDamage = baseDamage * (5 * level);
	
	int random = RandomInt::generateInt(0, 100);

	if (random < critChance) {
		totalDamage = totalDamage * 1.5;
	}
	
	if (random < missChance) {
		totalDamage = 0;
	}
	
	return totalDamage;
}


