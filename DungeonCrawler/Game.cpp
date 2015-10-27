#include "stdafx.h"
#include "Game.h"
#include "LevelFactory.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ItemFactory.h"


Game::Game()
{
	InitialSetup();
}


Game::~Game()
{
}

Player* Game::getPlayer()
{
	return player;
}

void Game::InitialSetup()
{
	level = LevelFactory::Instance()->FirstLevel();
	player = new Player();
	player->setCurrentRoom(level->getStartRoom());

	ItemFactory::GetInstance()->CreateItem("test");
}

