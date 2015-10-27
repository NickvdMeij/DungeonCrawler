#include "stdafx.h"
#include "MapCommand.h"


MapCommand::MapCommand()
{
}


MapCommand::~MapCommand()
{
}

void MapCommand::Run(list<string>* parameters, Game * game)
{
	game->getLevel()->printDungeon();
}
