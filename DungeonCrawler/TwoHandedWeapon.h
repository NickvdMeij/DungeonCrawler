#pragma once
#include "Equipable.h"
class TwoHandedWeapon : public Equipable
{
public:
	TwoHandedWeapon();
	~TwoHandedWeapon();
	virtual void Equip(Player p) const;
};

