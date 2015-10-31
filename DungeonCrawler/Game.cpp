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
	running = true;
	lf = new LevelFactory();
	level = lf->FirstLevel();

	ItemFactory* itemFactory = new ItemFactory();
	Weapon* w = itemFactory->CreateWeapon(1);
	Shield* s = itemFactory->CreateShield(1);
	
	player = new Player();
	player->setCurrentRoom(level->getStartRoom());
	player->getCurrentRoom()->visitRoom();
	player->setLevel(1);
	player->setCurrentHealth(100);
	player->setTotalHealth(200);
	player->setExperience(0);
	player->setName("Derp");
	player->setMainHand(w);
	player->setOffHand(s);

}

