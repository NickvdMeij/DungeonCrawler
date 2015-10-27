#include "stdafx.h"
#include "HelpCommand.h"
#include <iostream>

using namespace std;
HelpCommand::HelpCommand()
{
}


HelpCommand::~HelpCommand()
{
}

void HelpCommand::Run(list<string>* parameters, Game* game)
{
	cout << endl;
	cout << "Help" << endl;
	cout << "--  help           - Generates a list with commands you can execute with a small description what they do" << endl;
	cout << "--  help <command> - More info about a specific command" << endl;
	cout << "--  clear          - Clears the screen" << endl;
	cout << "--  av             - Available commands you can execute" << endl;
	cout << "--  stats          - Gives info about your character" << endl;
	cout << "--  gear           - Gives you an overview of your current gear" << endl;
	cout << "--  bags           - Gives you an overview of the items you are carrying" << endl;
	cout << endl << endl;
}
