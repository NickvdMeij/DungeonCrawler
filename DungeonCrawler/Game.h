#pragma once
#include <list>
#include "Player.h"
#include "Level.h"
#include "Enemy.h"

class Game
{
public:
	Game();
	~Game();
	Player* getPlayer();
private:
	Level* level;
	Player* player;
	std::list<Enemy*> enemies;
	void InitialSetup();
};

