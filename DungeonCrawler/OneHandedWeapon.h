#pragma once
#include "Equipable.h"
class OneHandedWeapon :
	public Equipable
{
public:
	OneHandedWeapon();
	~OneHandedWeapon();

	virtual void Equip(Player p) const;
};

