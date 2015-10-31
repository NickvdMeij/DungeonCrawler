#pragma once
#include "Command.h"
class PlayerInfoCommand :
	public Command
{
public:
	PlayerInfoCommand();
	~PlayerInfoCommand();
	void Run(list<string>* parameters, Game * game);
};

