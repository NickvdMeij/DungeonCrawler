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
	cout << endl << endl;
}
