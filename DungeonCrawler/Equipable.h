#pragma once
#include "Item.h"
#include "Player.h"
class Equipable :
	public Item
{
public:
	Equipable();
	~Equipable();
	virtual void Equip(Player p) const=0;
};

