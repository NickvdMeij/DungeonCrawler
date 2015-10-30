#pragma once
#include <list>
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "LevelFactory.h"

class Game
{
public:
	Game();
	~Game();
	Player* getPlayer();
	Level* getLevel();
private:
	Level* level;
	LevelFactory* lf;
	Player* player;
	std::list<Enemy*> enemies;

	void InitialSetup();
};

