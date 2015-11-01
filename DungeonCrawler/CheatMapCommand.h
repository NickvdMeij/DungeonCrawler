#pragma once
#include "Command.h"
class CheatMapCommand :
	public Command
{
public:
	CheatMapCommand();
	~CheatMapCommand();
	void Run(list<string>* parameters, Game* game);
};

