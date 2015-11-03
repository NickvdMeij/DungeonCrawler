#include "stdafx.h"
#include "RestCommand.h"


RestCommand::RestCommand()
{
}


RestCommand::~RestCommand()
{
}

void RestCommand::Run(list<string>* parameters, Game * game)
{
	Player* p = game->getPlayer();
	if (p->getCurrentHealth() < p->getTotalHealth()) {
		int chance = 20;
		int randomEnemy = rnd.generateInt(0, 100);
		int restAmount = 20 + (2 * p->getLevel());

		if (chance > randomEnemy) {
			Enemy* enemy = new Enemy();
			enemy->setIsAlive(true);
			enemy->setName("Goblin");
			enemy->setAttack(25 * game->getLevel()->getFloor());
			enemy->setDefence(10 * game->getLevel()->getFloor());
			enemy->setHealth(100 * game->getLevel()->getFloor());

			delete p->getCurrentRoom()->getEnemy();
			p->getCurrentRoom()->setEnemy(enemy);
			p->setCurrentHealth(p->getCurrentHealth() + (restAmount / 2));
			std::cout << "Halfway your rest you got interrupted by an enemy!" << endl;
		}
		else {
			p->setCurrentHealth(p->getCurrentHealth() + restAmount);
			std::cout << "After a little rest your hero feels a bit better without being found." << endl;
		}
	}
	else {
		std::cout << "Your hero doesn't need to rest." << endl;
	}
}
