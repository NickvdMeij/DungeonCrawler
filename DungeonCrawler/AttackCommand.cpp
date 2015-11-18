#include "stdafx.h"
#include "AttackCommand.h"
#include "ItemFactory.h"
#include <sstream>


AttackCommand::AttackCommand()
{
}


AttackCommand::~AttackCommand()
{
}

void AttackCommand::Run(list<string>* parameters, Game * game) {
	if (game->getPlayer()->getCurrentRoom()->hasEnemy()) {
		int trueDamage = game->getPlayer()->getMainHand()->getDamage();
		int damage = trueDamage - game->getPlayer()->getCurrentRoom()->getEnemy()->getDefence();

		if (damage < 0) {
			damage = 0;
		}
		std::cout << "You hitted the enemy for " << damage << " damage" << std::endl;

		game->getPlayer()->getCurrentRoom()->getEnemy()->takeDamage(trueDamage);

		if (game->getPlayer()->getCurrentRoom()->getEnemy()->getHealth() == 0) {
			delete game->getPlayer()->getCurrentRoom()->getEnemy();
			game->getPlayer()->getCurrentRoom()->setEnemy(nullptr);

			std::cout << "The enemy has died!" << std::endl;
			std::cout << "You recieved 200xp!" << std::endl;
			game->getPlayer()->setExperience(game->getPlayer()->getExperience() + 200);

			int dropChance = 101;
			int random = RandomInt::generateInt(0, 100);

			if (dropChance >= random) {
				int weaponShield = RandomInt::generateInt(0, 1);
				if (weaponShield) {
					Weapon* weapon = game->getItemFactory()->CreateWeapon(game->getPlayer()->getLevel());

					std::cout << "The enemy dropped his weapon" << endl;
					std::cout << "Weapon: " << weapon->getName() << " L" << weapon->getLevel() << endl;
					std::cout << "Base Attack: " << weapon->getBaseDamage() << endl;
					std::cout << " -- Critical Chance: " << weapon->getCriticalChance() << endl;
					std::cout << " -- Miss Chance: " << weapon->getMissChance() << endl;
					std::cout << "Current Weapon: " << game->getPlayer()->getMainHand()->getName() << " L" << game->getPlayer()->getMainHand()->getLevel() << endl;
					std::cout << " -- Base Attack: " << game->getPlayer()->getMainHand()->getBaseDamage() << endl;
					std::cout << " -- Critical Chance: " << game->getPlayer()->getMainHand()->getCriticalChance() << "%" << endl;
					std::cout << " -- Miss Chance: " << game->getPlayer()->getMainHand()->getMissChance() << "%" << endl;
					bool incorrect = true;

					while (incorrect) {
						std::cout << "Would you like to equip this weapon? (y/n)";

						std::string input;
						getline(cin, input);

						if (input == "y") {
							delete game->getPlayer()->getMainHand();
							game->getPlayer()->setMainHand(weapon);
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
				else {
					Shield* shield = game->getItemFactory()->CreateShield(game->getPlayer()->getLevel());

					std::cout << "The enemy dropped his shield" << endl;
					std::cout << "Shield: " << shield->getName() << " L" << shield->getLevel() << endl;
					std::cout << " -- Base Defence: " << shield->getBaseDefence() << endl;
					std::cout << " -- Block Chance: " << shield->getBlockChance() << endl;
					std::cout << "Current Shield: " << game->getPlayer()->getOffHand()->getName() << " L" << game->getPlayer()->getOffHand()->getLevel() << endl;
					std::cout << " -- Base Defence: " << game->getPlayer()->getOffHand()->getBaseDefence() << endl;
					std::cout << " -- Block Chance: " << game->getPlayer()->getOffHand()->getBlockChance() << "%" << endl;
					bool incorrect = true;

					while (incorrect) {
						std::cout << "Would you like to equip this shield? (y/n)";

						std::string input;
						getline(cin, input);

						if (input == "y") {
							delete game->getPlayer()->getOffHand();
							game->getPlayer()->setOffHand(shield);
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
		}
		else {
			std::cout << "The enemy is alive and attacks you back!" << std::endl;
			game->getPlayer()->TakeDamage(game->getPlayer()->getCurrentRoom()->getEnemy()->getDamage());
			std::cout << "Your current health is now " + game->getPlayer()->getCurrentHealth() << endl;
			if (game->getPlayer()->getCurrentHealth() < 0) {
				std::cout << "Your died... GAME OVER!" << endl;
				game->finish();

				cin.get();
			}
		}
	}
}
