#include "stdafx.h"
#include "GameController.h"
#include "DungeonGenerator.h"
#include "LevelFactory.h"
#include "Player.h"
#include <iostream>

using namespace std;

GameController::GameController()
{
	if (Setup()) {
		
		while (true) {
			Run();
		}
	}
}


GameController::~GameController()
{
}


// Run the gameloop
void GameController::Run()
{
	// handle events
	// move enemies
	// 
	GameController::CommandListener.Listen();
}


// Setup the game
bool GameController::Setup()
{
	LevelFactory *levelFactory = LevelFactory::Instance();
	Level* currentLevel = levelFactory->FirstLevel();

	Player player;
	player.setCurrentRoom(currentLevel->getStartRoom());

	return true;
}
