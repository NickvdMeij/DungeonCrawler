#pragma once
#include "Command.h"
class LookCommand :
	public Command
{
public:
	LookCommand();
	~LookCommand();
	void Run(list<string>* parameters, Game * game);
};

