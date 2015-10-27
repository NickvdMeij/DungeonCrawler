#pragma once
#include "Item.h"
class Shield : public Item
{
public:
	Shield();
	~Shield();
	int getDefence() { return defence; }
	void setDefence(int i) { defence = i; }
protected:
	int defence;
};

