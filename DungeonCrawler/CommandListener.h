#pragma once

#include "CommandFactory.h"

class CommandListener
{
private:
	CommandFactory commandFactory;
public:
	CommandListener();
	~CommandListener();
	void Listen();
};

