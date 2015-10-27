#pragma once
#include "item.h"
#include <vector>
using namespace std;

class Inventory
{
public:
	Inventory();
	~Inventory();
	void addItem(Item item);
	void removeItem(Item item);
	bool hasItem(Item item);
private:
	vector<Item> items;
};

