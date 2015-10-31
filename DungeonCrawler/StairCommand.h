#pragma once
#include "Command.h"
class StairCommand : 
	public Command
{
public:
	StairCommand();
	~StairCommand();
	void Run(list<string>* parameters, Game* game);
};

