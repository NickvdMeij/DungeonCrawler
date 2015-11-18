#include "stdafx.h"
#include "LookCommand.h"

#include <sstream>


LookCommand::LookCommand()
{
}


LookCommand::~LookCommand()
{
	std::cout << "delete lookCommand" << std::endl;
}

void LookCommand::Run(list<string>* parameters, Game * game)
{
	std::cout << game->getPlayer()->getCurrentRoom()->GetDescripton() << std::endl;

	if (game->getPlayer()->getCurrentRoom() == game->getLevel()->getStairRoom()) {
		std::cout << "This room has a stair going down" << std::endl;
	}

	if (game->getPlayer()->getCurrentRoom() == game->getLevel()->getStartRoom() && game->getLevel()->getFloor() != 1) {
		std::cout << "This room has a stair going up" << std::endl;
	}

	if (game->getPlayer()->getCurrentRoom()->DoesRoomHaveDoorway(Room::Direction::North)) {
		std::cout << "This room has a door to the north" << std::endl;
	}

	if (game->getPlayer()->getCurrentRoom()->DoesRoomHaveDoorway(Room::Direction::East)) {
		std::cout << "This room has a door to the east" << std::endl;
	}

	if (game->getPlayer()->getCurrentRoom()->DoesRoomHaveDoorway(Room::Direction::South)) {
		std::cout << "This room has a door to the south" << std::endl;
	}

	if (game->getPlayer()->getCurrentRoom()->DoesRoomHaveDoorway(Room::Direction::West)) {
		std::cout << "This room has a door to the west" << std::endl;
	}

	if (game->getPlayer()->getCurrentRoom()->hasEnemy()) {
		std::cout << std::endl;
		std::cout << "!!! This room has an Enemy !!!" << std::endl;
		std::cout << "Enemy Name: " << game->getPlayer()->getCurrentRoom()->getEnemy()->getName() << std::endl;
		std::cout << "Enemy Health: " << game->getPlayer()->getCurrentRoom()->getEnemy()->getHealth() << std::endl;
		std::cout << "Enemy Attack: " << game->getPlayer()->getCurrentRoom()->getEnemy()->getAttack() << std::endl;
		std::cout << "Enemy Defence: " << game->getPlayer()->getCurrentRoom()->getEnemy()->getDefence() << std::endl;
	}

	//find weapon and equip or leave on the ground
}
