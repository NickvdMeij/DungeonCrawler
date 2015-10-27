#include "stdafx.h"
#include "GameController.h"

GameController::GameController()
{
	game = new Game();

	while (true) {
		Run();
	}
}


GameController::~GameController()
{
}

// Run the gameloop
void GameController::Run()
{
	// handle events
	// move enemies
	// 
	std::cout << game->getPlayer()->getCurrentRoom().GetXPosition() << " - " << game->getPlayer()->getCurrentRoom().GetYPosition() << std::endl;
	Listen();
}

void GameController::Listen()
{
	std::string s;

	cout << "Please give a command (type help for a list of commands): " << endl;
	getline(cin,s);

	cout << s;

	list<string>* parameters = new list<string>();

	std::string delimiter = " ";

	s += " endLine";

	size_t pos = 0;
	bool first = true;
	std::string token;
	std::string command;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		
		token = s.substr(0, pos);

		if (first) {
			command = token;
			first = false;
		}
		else
		{
			parameters->push_back(token);
		}

		s.erase(0, pos + delimiter.length());
	}

	commandFactory.CreateCommand(command, parameters, game);
}
