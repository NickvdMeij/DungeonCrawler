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
		d = it->second;
		game->getPlayer()->MoveDirection(d);

		const int trapChance = 20;
		int random = RandomInt::generateInt(0, 100);

		if (trapChance > random) {
			game->getPlayer()->setCurrentHealth(game->getPlayer()->getCurrentHealth() - 10);
			std::cout << "There was a trap in the next room, you activated it by accident and lost 10hp" << std::endl;
		}
	}
	else {
		cout << "Second part of command is unknown." << endl;
	}
}