#pragma once
#include "Command.h"

class HelpCommand : public Command
{
public:
	HelpCommand();
	~HelpCommand();
	void Run(list<string>* parameters, Game* game);
};

