#pragma once
#include "stdafx.h"
#include "Item.h"
#include "Weapon.h"
#include "Shield.h"
#include <vector>

class ItemFactory
{
public:
	ItemFactory();
	~ItemFactory();
	Item CreateItem(std::string type);
	static ItemFactory* GetInstance() {
		static ItemFactory instance;
		return &instance;
	}
	
private:
	void readWeaponsFile();
	void readShieldsFile();
	ItemFactory& operator=(const ItemFactory&) { return *this; }
	vector<Weapon> weapons;
	vector<Shield> shields;
};

