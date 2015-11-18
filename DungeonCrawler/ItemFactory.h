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
	Weapon* CreateWeapon(int l);
	Shield* CreateShield(int l);
	
private:
	void readWeaponsFile();
	void readShieldsFile();
	vector<Weapon*> weapons;
	vector<Shield*> shields;
};

