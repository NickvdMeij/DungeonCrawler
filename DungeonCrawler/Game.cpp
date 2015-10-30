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

Level * Game::getLevel()
{
	return level;
}

void Game::InitialSetup()
{
	
	lf = new LevelFactory();
	level = lf->FirstLevel();

	player = new Player();
	player->setCurrentRoom(level->getStartRoom());
	player->getCurrentRoom()->visitRoom();

	ItemFactory::GetInstance()->CreateItem("test");
}

