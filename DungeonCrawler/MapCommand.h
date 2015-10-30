#pragma once
#include "Command.h"
class MapCommand :
	public Command
{
public:
	MapCommand();
	~MapCommand();
	void Run(list<string>* parameters, Game* game);
};

