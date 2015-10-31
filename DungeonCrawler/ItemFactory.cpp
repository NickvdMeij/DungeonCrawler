#include "stdafx.h"
#include "ItemFactory.h"
#include <iostream>
#include <fstream>
#include <string>
#include "RandomInt.h"
#include "Game.h"

ItemFactory::ItemFactory()
{
	readWeaponsFile();
	readShieldsFile();
}


ItemFactory::~ItemFactory()
{
}

Weapon* ItemFactory::CreateWeapon(int level)
{
	int random = RandomInt::generateInt(0, weapons.size());
	Weapon* w = weapons[random];

	w->setLevel(level);

	return w;
}

Shield* ItemFactory::CreateShield(int level)
{
	int random = RandomInt::generateInt(0, shields.size());

	Shield* s = shields[random];

	s->setLevel(level);

	return s;
}

void ItemFactory::readWeaponsFile()
{
	const string textfile{ "./Items/Weapons.txt" };

	ifstream input_file{ textfile };

	string line, weaponName;
	int baseDamage, critChance, missChance;

	while (getline(input_file, line)) {
		input_file >> weaponName >> baseDamage >> critChance >> missChance;

		Weapon* w = new Weapon();
		w->setBaseDamage(baseDamage);
		w->setCriticalChance(critChance);
		w->setMissChance(missChance);
		w->setName(weaponName);

		weapons.push_back(w);
	}
}

void ItemFactory::readShieldsFile()
{
	const string textfile{ "./Items/Shields.txt" };

	ifstream input_file{ textfile };

	string line, shieldName;
	int baseDefence, blockChance;

	while (getline(input_file, line)) {
		input_file >> shieldName >> baseDefence >> blockChance;

		Shield* s = new Shield();
		s->setBaseDefence(baseDefence);
		s->setBlockChance(blockChance);
		s->setName(shieldName);

		shields.push_back(s);
	}
}
