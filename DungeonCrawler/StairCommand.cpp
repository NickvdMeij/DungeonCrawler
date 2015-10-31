#include "stdafx.h"
#include "StairCommand.h"


StairCommand::StairCommand()
{
}


StairCommand::~StairCommand()
{
}

void StairCommand::Run(list<string>* parameters, Game * game)
{
	if (game->getPlayer()->getCurrentRoom() == game->getLevel()->getStairRoom()) {
		game->nextLevel();
		std::cout << "You took the stair to the next level." << endl;
	}
	else {
		std::cout << "This room doesn't have a stair." << endl;
	}
}
