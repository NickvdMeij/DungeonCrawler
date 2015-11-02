#include "stdafx.h"
#include "QuitCommand.h"


QuitCommand::QuitCommand()
{
}


QuitCommand::~QuitCommand()
{
}

void QuitCommand::Run(list<string>* parameters, Game * game) {
	game->finish();
}