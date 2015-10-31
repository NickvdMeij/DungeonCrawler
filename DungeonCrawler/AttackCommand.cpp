#include "stdafx.h"
#include "AttackCommand.h"


AttackCommand::AttackCommand()
{
}


AttackCommand::~AttackCommand()
{
}

void AttackCommand::Run(list<string>* parameters, Game * game) {
	if (game->getPlayer()->getCurrentRoom()->hasEnemy()) {
		int trueDamage = game->getPlayer()->getMainHand()->getDamage();

		std::cout << "You hitted the enemy for " << trueDamage - game->getPlayer()->getCurrentRoom()->getEnemy()->getDefence() << " damage" << std::endl;

		game->getPlayer()->getCurrentRoom()->getEnemy()->takeDamage(trueDamage);

		if (game->getPlayer()->getCurrentRoom()->getEnemy()->getHealth() == 0) {
			std::cout << "The enemy has died!" << std::endl;
		}
		else {
			std::cout << "The enemy is alive and attacks you back!" << std::endl;
			game->getPlayer()->TakeDamage(game->getPlayer()->getCurrentRoom()->getEnemy()->getDamage());
		}
	}
}
