#include "stdafx.h"
#include "CommandFactory.h"
#include <map>
#include "HelpCommand.h"
#include <iostream>

CommandFactory::CommandFactory()
{
	stringMap["error"] = CommandString::error;
	stringMap["help"] = CommandString::help;
}


CommandFactory::~CommandFactory()
{
}

void CommandFactory::CreateCommand(string commandString)
{
	CommandString string = stringMap[commandString];

	switch (string) {
		default: Error(); break;
		case help: RunHelpCommand(); break;
	}
}

void CommandFactory::RunHelpCommand()
{
	HelpCommand* helpCommand = new HelpCommand();
	helpCommand->Run();
}

void CommandFactory::Error()
{
	cout << "That command is not available. Type 'help' for a list of available commands." << endl;
	cout << "" << endl;
}

