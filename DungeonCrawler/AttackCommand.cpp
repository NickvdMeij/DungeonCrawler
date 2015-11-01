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
		int damage = trueDamage - game->getPlayer()->getCurrentRoom()->getEnemy()->getDefence();

		if (damage < 0) {
			damage = 0;
		}
		std::cout << "You hitted the enemy for " << damage << " damage" << std::endl;

		game->getPlayer()->getCurrentRoom()->getEnemy()->takeDamage(trueDamage);

		if (game->getPlayer()->getCurrentRoom()->getEnemy()->getHealth() == 0) {
			std::cout << "The enemy has died!" << std::endl;
			std::cout << "You recieved 200xp!" << std::endl;
			game->getPlayer()->setExperience(game->getPlayer()->getExperience() + 200);
		}
		else {
			std::cout << "The enemy is alive and attacks you back!" << std::endl;
			game->getPlayer()->TakeDamage(game->getPlayer()->getCurrentRoom()->getEnemy()->getDamage());
			std::cout << "Your current health is now " + game->getPlayer()->getCurrentHealth() << endl;
			if (game->getPlayer()->getCurrentHealth() < 0) {
				std::cout << "Your died... GAME OVER!" << endl;
				game->finish();

				cin.get();
			}
		}
	}
}
