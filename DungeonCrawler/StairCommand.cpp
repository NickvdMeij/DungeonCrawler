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
	}
	else {
		std::cout << "Deze kamer bevat geen trap" << endl;
	}
}
