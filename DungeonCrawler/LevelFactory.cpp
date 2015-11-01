#include "stdafx.h"
#include "LevelFactory.h"


LevelFactory::LevelFactory()
{
	Register(1, Level(5, 5, 1));
	Register(2, Level(6, 6, 2));
	Register(3, Level(7, 7, 3));
	Register(4, Level(8, 8, 4));
}

LevelFactory::~LevelFactory()
{
	levelMap.clear();
}

void LevelFactory::Register(const int levelId, Level level)
{
	levelMap[levelId] = level;
}

Level* LevelFactory::NextLevel(Level* currentLevel)
{
	map<int, Level>::iterator it = levelMap.find(currentLevel->getFloor() + 1);
	if (it != levelMap.end())
		return &it->second;
	return NULL;
}

Level* LevelFactory::PreviousLevel(Level* currentLevel)
{
	map<int, Level>::iterator it = levelMap.find(currentLevel->getFloor() - 1);
	if (it != levelMap.end())
		return &it->second;
	return NULL;
}

Level* LevelFactory::FirstLevel()
{
	map<int, Level>::iterator it = levelMap.find(1);
	if (it != levelMap.end())
		return &it->second;
	return NULL;
}
