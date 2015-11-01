#pragma once
#include "level.h"
#include <iostream>
#include <map>
using namespace std;

class LevelFactory
{
private:
	map<int, Level*> levelMap;
public:
	LevelFactory();
	~LevelFactory();

	void Register(const int levelId, Level* level);
	Level* NextLevel(Level* currentLevel);
	Level * PreviousLevel(Level * currentLevel);
	Level* FirstLevel();
};

