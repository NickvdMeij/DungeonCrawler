#pragma once
#include "Command.h"
class ViewCommand :
	public Command
{
public:
	ViewCommand();
	~ViewCommand();
	void Run(list<string>* parameters, Game * game);
};

