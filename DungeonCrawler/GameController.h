#pragma once
#include "Game.h"
#include "CommandFactory.h"
#include "ItemFactory.h"

class GameController
{
public:
	GameController();
	~GameController();


private:
	CommandFactory commandFactory;
	Game* game;
	ItemFactory* itemFactory;
	void Listen();
	void Run();

};

