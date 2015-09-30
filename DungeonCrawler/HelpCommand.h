#pragma once

#include "Command.h"

class HelpCommand : Command
{
public:
	HelpCommand();
	~HelpCommand();
	void Run();
};

