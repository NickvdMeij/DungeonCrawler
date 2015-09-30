#pragma once
#include "CommandListener.h"

class GameController
{
public:
	GameController();
	~GameController();
	// Run the gameloop
	void Run();
private:
	CommandListener CommandListener;
	// Setup the game
	bool Setup();
};

