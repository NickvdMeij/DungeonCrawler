#include "stdafx.h"
#include "HandgrenadeCommand.h"
#include <queue>
#include <vector>


HandgrenadeCommand::HandgrenadeCommand()
{
}


HandgrenadeCommand::~HandgrenadeCommand()
{
}

void HandgrenadeCommand::Run(list<string>* parameters, Game * game)
{
	Room* startRoom = game->getPlayer()->getCurrentRoom();
}
