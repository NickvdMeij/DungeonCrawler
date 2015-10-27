#pragma once

#include <string>
#include <map>
#include <list>
#include "Game.h"
#include "Command.h"

using namespace std;
class CommandFactory
{

private:
	map<string, Command*> mapping;
public:
	CommandFactory();
	~CommandFactory();
	void CreateCommand(string commandString, list<string>* parameters, Game* game);
};

