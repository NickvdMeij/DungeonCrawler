#include "stdafx.h"
#include "CommandListener.h"
#include "Command.h"
#include "CommandFactory.h"
#include <iostream>
#include <string>

using namespace std;
CommandListener::CommandListener()
{
}


CommandListener::~CommandListener()
{
}

void CommandListener::Listen()
{
	string tempCommand;

	cout << "Please give a command (type help for a list of commands): ";
	cin >> tempCommand;

	commandFactory.CreateCommand(tempCommand);
}
