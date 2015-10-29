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

	ItemFactory* itemFactory = new ItemFactory();
	Weapon w = itemFactory->CreateWeapon(1);
	Shield s = itemFactory->CreateShield(1);
	
	player = new Player();
	player->setCurrentRoom(level->getStartRoom());
	player->setLevel(1);
	player->setCurrentHealth(100);
	player->setTotalHealth(200);
	player->setExperience(0);
	player->setName("Derp");
	player->setMainHand(&w);
	player->setOffHand(&s);

	player->TakeDamage(player->getMainHand()->getDamage());	
}

