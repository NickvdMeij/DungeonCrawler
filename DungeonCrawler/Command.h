#pragma once
#include <list>
#include "Game.h"

class Command
{
public:
	Command();
	~Command();
	virtual void Run(list<string>* parameters, Game* game);
};

