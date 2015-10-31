#include "stdafx.h"
#include "PlayerInfoCommand.h"
#include <sstream>


PlayerInfoCommand::PlayerInfoCommand()
{
}


PlayerInfoCommand::~PlayerInfoCommand()
{
}

void PlayerInfoCommand::Run(list<string>* parameters, Game * game)
{
	Player* player = game->getPlayer();

	std::cout << "Name: " << player->getName() << endl;
	std::cout << "Health: " << player->getCurrentHealth() << "/" << player->getTotalHealth() << endl;
	std::cout << "Level: " << player->getLevel() << endl;
	std::cout << "Experience: " << player->getExperience() << endl;
	std::cout << "Main hand: " << player->getMainHand()->getName() << " L" << player->getMainHand()->getLevel() << endl;
	std::cout << " -- Base Attack: " << player->getMainHand()->getBaseDamage() << endl;
	std::cout << " -- Critical Chance: " << player->getMainHand()->getCriticalChance() << "%" << endl;
	std::cout << " -- Miss Chance: " << player->getMainHand()->getMissChance() << "%" << endl;
	std::cout << "Off hand: " << player->getOffHand()->getName() << " L" << player->getOffHand()->getLevel() << endl;
	std::cout << " -- Base Defence: " << player->getOffHand()->getBaseDefence() << endl;
	std::cout << " -- Block Chance: " << player->getOffHand()->getBlockChance() << "%" << endl;
}
