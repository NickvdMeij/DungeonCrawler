#include "stdafx.h"
#include "ItemFactory.h"
#include <iostream>
#include <fstream>
#include <string>

ItemFactory::ItemFactory()
{
	readWeaponsFile();
	readShieldsFile();
}


ItemFactory::~ItemFactory()
{
}

Item ItemFactory::CreateItem(string type)
{
	Item* item = new Item();
	return *item;
}

void ItemFactory::readWeaponsFile()
{
	const string textfile{ "./Items/Weapons.txt" };

	ifstream input_file{ textfile };

	string line, weaponName;
	int baseDamage, critChance, missChange;

	while (getline(input_file, line)) {
		input_file >> weaponName >> baseDamage >> critChance >> missChange;

		//cout << weaponName << " " << baseDamage << " " << critChance << " " << missChange << endl;
	}

	


}

void ItemFactory::readShieldsFile()
{
	const string textfile{ "./Items/Shields.txt" };

	ifstream input_file{ textfile };

	string line, weaponName;
	int baseDamage, critChance, missChange;

	while (getline(input_file, line)) {
		input_file >> weaponName >> baseDamage >> critChance >> missChange;

		//cout << weaponName << " " << baseDamage << " " << critChance << " " << missChange << endl;
	}
}
