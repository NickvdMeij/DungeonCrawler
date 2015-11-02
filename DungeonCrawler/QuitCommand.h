#pragma once
#include "Command.h"
class QuitCommand :
	public Command
{
public:
	QuitCommand();
	~QuitCommand();
	void Run(list<string>* parameters, Game * game);
};

