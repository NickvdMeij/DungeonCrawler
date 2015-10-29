#pragma once
#include "Command.h"
class HandgrenadeCommand :
	public Command
{
public:
	HandgrenadeCommand();
	~HandgrenadeCommand();
	void Run(list<string>* parameters, Game* game);
};

