#include "stdafx.h"
#include "Weapon.h"
#include "RandomInt.h"


Weapon::Weapon()
{
}


Weapon::~Weapon()
{
	cout << "weapon destuctor" << endl;
}

int Weapon::getDamage()
{
	int totalDamage = 0;

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


