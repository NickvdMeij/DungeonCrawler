#include "stdafx.h"
#include "GameController.h"

GameController::GameController()
{
	game = new Game();

	while (game->isRunning()) {
		Run();
	}
}


GameController::~GameController()
{
}

// Run the gameloop
void GameController::Run()
{
	
	Listen();
	// game update
	// handle World Events
	// move enemies
	// 
}

void GameController::Listen()
{
	std::string s;

	cout << "Please give a command (type help for a list of commands): " << endl;
	getline(cin,s);

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
	cout << endl;
}
