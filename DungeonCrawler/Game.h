#pragma once
#include <list>
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "LevelFactory.h"
#include "ItemFactory.h"

class Game
{
public:
	Game();
	~Game();
	Player* getPlayer();
	Level* getLevel();
	ItemFactory* getItemFactory() { return itemFactory; }
	bool isRunning() { return running; };
	void finish();
	void nextLevel();
	void previousLevel();
	Game(const Game& other); // copy constructor
	Game(Game&& other); // move constructor
	Game& operator=(const Game& other); // copy assignment
	Game& operator=(Game&& other); // move assignment
private:
	Level* level;
	bool running;
	LevelFactory* lf;
	Player* player;
	void InitialSetup();
	ItemFactory* itemFactory;
};

