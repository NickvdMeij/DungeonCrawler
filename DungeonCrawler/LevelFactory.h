#pragma once
#include "level.h"
#include <iostream>
#include <map>
using namespace std;

class LevelFactory
{
private:
	LevelFactory();
	LevelFactory& operator=(const LevelFactory&) { return *this; }

	map<int, Level> levelMap;
public:
	~LevelFactory();

	static LevelFactory* Instance() {
		static LevelFactory instance;
		return &instance;
	}
	void Register(const int levelId, Level level);
	Level* NextLevel(Level* currentLevel);
	Level* FirstLevel();
};

