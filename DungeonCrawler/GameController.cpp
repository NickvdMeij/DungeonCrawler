#include "stdafx.h"
#include "GameController.h"
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
	return true;
}
