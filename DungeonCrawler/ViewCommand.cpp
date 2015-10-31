#include "stdafx.h"
#include "ViewCommand.h"
#include <sstream>


ViewCommand::ViewCommand()
{
}


ViewCommand::~ViewCommand()
{
}

void ViewCommand::Run(list<string>* parameters, Game * game) {
	if(parameters->size() < 2) {
		std::cout << "Please give an argument what you want to view (inventory/weapon/shield)" << std::endl;
	}

	std::cout << parameters->begin() << endl;
}
