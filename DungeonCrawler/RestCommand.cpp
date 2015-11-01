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
		p->setCurrentHealth(p->getCurrentHealth() + 20 + (2 * p->getLevel()));
		std::cout << "After a little rest your hero feels a bit better." << endl;
	}
	else {
		std::cout << "Your hero doesn't need to rest." << endl;
	}
}
