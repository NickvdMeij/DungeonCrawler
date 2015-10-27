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
	//----------Moet getest worden!!---------//
	for (int i = 0; i < items.size(); i++) {
		if (items[i].getId() == item.getId()) {
			items.erase(items.begin() + i);
		}
	}
}

bool Inventory::hasItem(Item item)
{
	for (int i = 0; i < items.size(); i++) {
		if (items[i].getId() == item.getId()) {
			return true;
		}
	}

	return false;
}
