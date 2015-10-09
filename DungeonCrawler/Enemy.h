#pragma once

#include <iostream>
using namespace std;

class Enemy {
private:
	string name;
public:
	Enemy();
	~Enemy();
	string GetName();
};