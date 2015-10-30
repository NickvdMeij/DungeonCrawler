#pragma once
#include "Command.h"
class TalismanCommand :
	public Command
{
public:
	TalismanCommand();
	~TalismanCommand();
	void Run(list<string>* parameters, Game* game);
};

