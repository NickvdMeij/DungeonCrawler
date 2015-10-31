#pragma once
#include "Command.h"
#include "Game.h"
class AttackCommand :
	public Command
{
public:
	AttackCommand();
	~AttackCommand();
	void Run(list<string>* parameters, Game * game);
};

