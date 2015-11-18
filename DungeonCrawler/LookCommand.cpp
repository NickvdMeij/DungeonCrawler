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

	if (game->getPlayer()->getCurrentRoom()->isTrapped()) {
		std::cout << std::endl;
		std::cout << "!!! This room has a trap !!!" << std::endl;
		bool incorrect = true;

		while (incorrect) {
			std::cout << "Would you like to disarm the trap? (y/n)";

			std::string input;
			getline(cin, input);

			if (input == "y") {
				int trapChance = 60 + (game->getPlayer()->getLevel() * 5);
				int randomTrap = RandomInt::generateInt(0, 100);

				if (trapChance > randomTrap) {
					game->getPlayer()->getCurrentRoom()->setTrapped(false);
					std::cout << "You succesfully disarmed the trap";
				}
				else {
					game->getPlayer()->getCurrentRoom()->setTrapped(false);
					std::cout << "Disarming failed, the trap triggered and you lost 20 hp";
					game->getPlayer()->setCurrentHealth(game->getPlayer()->getCurrentHealth() - 20);
					if (game->getPlayer()->getCurrentHealth() < 0) {
						std::cout << "Your died... GAME OVER!" << endl;
						game->finish();

						cin.get();
					}
				}
				incorrect = false;
			}
			else if (input == "n") {
				incorrect = false;
			}
			else {
				std::cout << "Wrong input" << endl;
			}
		}
	}
}
