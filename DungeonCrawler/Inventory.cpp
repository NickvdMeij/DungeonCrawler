#include "stdafx.h"
#include "Inventory.h"


Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}

void Inventory::addItem(Item item)
{
	items.push_back(item);
}

void Inventory::removeItem(Item item)
{
	//remove item
}
