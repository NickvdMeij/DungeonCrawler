#include "stdafx.h"
#include "Command.h"
#include <iostream>

using namespace std;
Command::Command()
{
}


Command::~Command()
{
}

void Command::Run()
{
	cout << "Command" << endl;
}
