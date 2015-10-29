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
	}
	else {
		cout << "Second part of command is unknown." << endl;
	}
}