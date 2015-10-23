#include "stdafx.h"
#include "GameController.h"
#include "DungeonGenerator.h"
#include "Level.h"
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
	Level lev1(5, 5, 1);
	Level lev2(6, 6, 2);
	Level lev3(7, 7, 3);
	Level lev4(8, 8, 4);
	return true;
}
