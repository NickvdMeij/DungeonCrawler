#pragma once
#include "Command.h"
class RestCommand :
	public Command
{
private:
	RandomInt rnd;
public:
	RestCommand();
	~RestCommand();
	void Run(list<string>* parameters, Game * game);
};

