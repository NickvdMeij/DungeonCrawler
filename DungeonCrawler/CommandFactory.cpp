#include "stdafx.h"
#include "CommandFactory.h"
#include <map>
#include "HelpCommand.h"
#include "GoCommand.h"
#include "TalismanCommand.h"
#include "MapCommand.h"
#include "CheatMapCommand.h"
#include "LookCommand.h"
#include "AttackCommand.h"
#include "PlayerInfoCommand.h"
#include "CompasCommand.h"
#include "HandgrenadeCommand.h"
#include "StairCommand.h"
#include <iostream>

CommandFactory::CommandFactory()
{
	mapping["help"] = new HelpCommand();
	mapping["go"] = new GoCommand();
	mapping["map"] = new MapCommand();
	mapping["talisman"] = new TalismanCommand();
	mapping["compass"] = new CompasCommand();
	mapping["grenade"] = new HandgrenadeCommand();
	mapping["look"] = new LookCommand();
	mapping["attack"] = new AttackCommand();
	mapping["player"] = new PlayerInfoCommand();
	mapping["stair"] = new StairCommand();
	mapping["cheat"] = new CheatMapCommand();
}


CommandFactory::~CommandFactory()
{
}


void CommandFactory::CreateCommand(string commandString, list<string>* parameters, Game* game)
{
	cout << endl;
	if (mapping[commandString]) {
		
		return mapping[commandString]->Run(parameters, game);
		
	}
	else {
		cout << "That command is not available, please pick another command or type 'help' for a list with available commands" << endl;
		cout << endl;
	}
	
}

