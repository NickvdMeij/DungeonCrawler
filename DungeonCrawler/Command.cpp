#include "stdafx.h"
#include "Command.h"
#include <iostream>

using namespace std;
Command::Command()
{
}


Command::~Command()
{
	std::cout << "command baseclass destructor" << endl;
}

void Command::Run(list<string>* parameters, Game * game)
{
}
