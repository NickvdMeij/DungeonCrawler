#include "stdafx.h"
#include "GoCommand.h"
#include "Player.h"


GoCommand::GoCommand()
{
	directions["north"] = Room::Direction::North;
	directions["east"] = Room::Direction::East;
	directions["south"] = Room::Direction::South;
	directions["west"] = Room::Direction::West;
}


GoCommand::~GoCommand()
{
}

void GoCommand::Run(list<string>* parameters, Game* game)
{
	Room::Direction d;
	map<string, Room::Direction>::iterator it = directions.find(*parameters->begin());
	if (it != directions.end()) {
		if (game->getPlayer()->getCurrentRoom()->isTrapped()) {
			game->getPlayer()->setCurrentHealth(game->getPlayer()->getCurrentHealth() - 20);
			game->getPlayer()->getCurrentRoom()->setTrapped(false);
			std::cout << "There was a trap in this room that you didn't disarm. You triggered it and lose 20hp" << std::endl;
			if (game->getPlayer()->getCurrentHealth() < 0) {
				std::cout << "Your died... GAME OVER!" << endl;
				game->finish();

				cin.get();
			}
		}
		d = it->second;
		game->getPlayer()->MoveDirection(d);
	}
	else {
		cout << "Second part of command is unknown." << endl;
	}
}