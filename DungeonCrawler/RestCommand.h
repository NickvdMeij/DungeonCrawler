#pragma once
#include "Command.h"
class RestCommand :
	public Command
{
public:
	RestCommand();
	~RestCommand();
	void Run(list<string>* parameters, Game * game);
};

