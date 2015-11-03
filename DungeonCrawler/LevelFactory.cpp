#include "stdafx.h"
#include "LevelFactory.h"


LevelFactory::LevelFactory()
{
	Register(1, new Level(5, 5, 1));
	Register(2, new Level(6, 6, 2));
	Register(3, new Level(7, 7, 3));
	Register(4, new Level(8, 8, 4));
}

LevelFactory::~LevelFactory()
{
	delete levelMap[1];
	delete levelMap[2];
	delete levelMap[3];
	delete levelMap[4];

	levelMap.clear();
}

void LevelFactory::Register(const int levelId, Level* level)
{
	levelMap[levelId] = level;
}

Level* LevelFactory::NextLevel(Level* currentLevel)
{
	map<int, Level*>::iterator it = levelMap.find(currentLevel->getFloor() + 1);
	if (it != levelMap.end())
		return it->second;
	return NULL;
}

Level* LevelFactory::PreviousLevel(Level* currentLevel)
{
	map<int, Level*>::iterator it = levelMap.find(currentLevel->getFloor() - 1);
	if (it != levelMap.end())
		return it->second;
	return NULL;
}

Level* LevelFactory::FirstLevel()
{
	map<int, Level*>::iterator it = levelMap.find(1);
	if (it != levelMap.end())
		return it->second;
	return NULL;
}
