#pragma once
#include <iostream>
using namespace std;

class Item
{
public:
	Item();
	~Item();
	void setName(string s) { name = s; }
	string getName() { return name; }
	void setDescription(string s) { description = s; }
	string setDescription() { return description; }
	int getId() { return id; }
	void setId(int i) { id = i; };
protected:
	int id;
	string name, description;
};

