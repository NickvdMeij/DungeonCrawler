#pragma once
#include <iostream>
using namespace std;

class Item
{
public:
	Item();
	~Item();
	void setName(string n) { name = n; }
	string getName() { return name; }
private:
	string name;
};

